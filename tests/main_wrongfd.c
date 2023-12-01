#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char *str = get_next_line(42);
	printf("Return:\n%s", str);
	if (!str)
		printf("\nTEST OK\n");
	free(str);
}
