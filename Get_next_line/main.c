
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	int fd;
	char *buff;
	int	 i;

	fd = open("input", O_RDONLY);

	i = 0;
	while (i < 7)
	{
		printf("result => %d\n", get_next_line(fd, &buff));
		printf("buffer => %s\n", buff);
		i++;
	}
	free(buff);
	return (0);
}
