/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/28 18:40:29 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/01 19:39:27 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "get_next_line.h"

bool	is_eol(t_static *persis)
{
	size_t	i;

	i = 0;
	while (i < persis->size)
	{
		if (persis->content[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

size_t	eol_index(t_static *persis)
{
	size_t	i;

	i = 0;
	while (i < persis->size)
	{
		if (persis->content[i] == '\n')
			return (i);
		i++;
	}
	return (persis->size - 1);
}

void	clearstatic(t_static *persis)
{
	free(persis->content);
	persis->content = NULL;
	persis->size = 0;
}
