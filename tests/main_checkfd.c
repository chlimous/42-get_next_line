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
