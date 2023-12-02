/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:40:50 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/02 18:17:48 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>

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
