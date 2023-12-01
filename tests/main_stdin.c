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
