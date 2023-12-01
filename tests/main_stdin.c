/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:00:52 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/01 22:00:53 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int i = 1;
	char *str;
	while ((str = get_next_line(0)))
	{
		printf("Iteration %d:\n%s", i, str);
		free(str);
		i++;
	}
}
