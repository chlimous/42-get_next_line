/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checkfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:00:40 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/01 22:00:44 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	i;

	fd = 0;
	i = 0;
	while (fd != -1)
	{
		fd = open("foo.txt", O_RDONLY);
		i++;
		printf("Open #%d -> %d\n", i, fd);
	}
}

// ulimit -Sn
