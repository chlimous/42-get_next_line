/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:40:50 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/01 20:11:17 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1023
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_static
{
	char	*content;
	size_t	size;
}	t_static;

char	*get_next_line(int fd);
bool	is_eol(t_static *persis);
size_t	eol_index(t_static *persis);
void	clearstatic(t_static *persis);

#endif
