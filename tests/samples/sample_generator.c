/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:40:57 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 00:57:09 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	int	j;
	char	c;

	if (argc != 4)
		return 1;
	fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    	if (fd == -1)
        	return 1;
	srand(time(NULL));
	while (i < atoi(argv[1]))
	{
		j = 0;
		while (j < atoi(argv[2]))
		{
			c = 'a' + (rand() % 26);
			write(fd, &c, 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	return 0;
}

