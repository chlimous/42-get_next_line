/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <chlimous@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/28 18:40:29 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/01 20:15:07 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
