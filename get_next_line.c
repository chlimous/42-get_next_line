/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/28 18:39:46 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/01 20:51:35 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "get_next_line.h"

static void	buffercat(t_static *persis, char *buffer, size_t bytesread)
{
	char		*content;
	size_t		i;
	size_t		j;

	content = malloc(sizeof(char) * (bytesread + persis->size));
	if (!content)
	{
		clearstatic(persis);
		return ;
	}
	i = 0;
	while (i < persis->size)
	{
		content[i] = persis->content[i];
		i++;
	}
	free(persis->content);
	j = 0;
	while (j < bytesread)
		content[i++] = buffer[j++];
	persis->content = content;
	persis->size += bytesread;
}

static int	trim_static(t_static *persis)
{
	char		*content;
	size_t		size;
	size_t		i;
	size_t		j;

	i = eol_index(persis) + 1;
	size = persis->size - i;
	if (!size)
		return (clearstatic(persis), 0);
	content = malloc(sizeof(char) * size);
	if (!content)
		return (clearstatic(persis), 1);
	j = 0;
	while (i < persis->size)
		content[j++] = persis->content[i++];
	free(persis->content);
	persis->size = size;
	persis->content = content;
	return (0);
}

static char	*build_line(t_static *persis)
{
	char	*line;
	size_t	linelen;
	size_t	i;

	linelen = eol_index(persis) + 1;
	i = 0;
	line = malloc(sizeof(char) * (linelen + 1));
	if (!line)
		return (clearstatic(persis), NULL);
	while (i < linelen)
	{
		line[i] = persis->content[i];
		i++;
	}
	line[linelen] = '\0';
	if (trim_static(persis))
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_static		persis;
	char				*buffer;
	ssize_t				bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	else
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	bytesread = 1;
	while (bytesread > 0 && !is_eol(&persis))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread > 0)
			buffercat(&persis, buffer, bytesread);
		if (!persis.size || bytesread == -1)
			return (clearstatic(&persis), free(buffer), NULL);
	}
	return (free(buffer), build_line(&persis));
}
