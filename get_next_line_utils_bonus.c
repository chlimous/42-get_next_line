/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/28 18:40:29 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/02 18:50:39 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

bool	is_eol(t_static *persis)
{
	size_t	i;
	size_t	j;

	i = persis->size - 1;
	j = 0;
	while (j < BUFFER_SIZE && i != (size_t)-1)
	{
		if (persis->content[i] == '\n')
			return (true);
		i--;
		j++;
	}
	return (false);
}

size_t	eol_index(t_static *persis)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = persis->size - 1;
	j = 0;
	temp = persis->size - 1;
	while (j < BUFFER_SIZE && i != (size_t)-1)
	{
		if (persis->content[i] == '\n')
			temp = i;
		i--;
		j++;
	}
	return (temp);
}

void	clearstatic(t_static *persis)
{
	free(persis->content);
	persis->content = NULL;
	persis->size = 0;
}
