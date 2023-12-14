/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checkfd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:00:40 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/14 18:41:56 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char 	*str;
	int	fd;
	int	i;

	fd = 0;
	i = 0;
	while (fd != -1)
	{
		fd = open("samples/foo.txt", O_RDONLY);
		str = get_next_line(fd);
		i++;
		printf("Open #%d -> %d | %s\n", i, fd, str);
	}
}

// change FD soft limit with ulimit -Sn before running the test
