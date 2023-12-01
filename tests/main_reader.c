#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	*str;

	if (argc < 3)
		return (1);
	int *fd = malloc(sizeof(int) * (argc - 2));
	i = 0;
	while (i < argc - 2)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	while (i <= atoi(argv[argc - 1]))
	{
		printf("Iteration %d:\n", i);
		j = 0;
		while (j < argc - 2)
		{
			str = get_next_line(fd[j]);
			printf("File %d: %s", j, str);
			if (!str)
				printf("\n");
			free(str);
			j++;
		}
		printf("\n");
		i++;
	}
	free(fd);
}
