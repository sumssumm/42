#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;

	fd = 0;
	fd = open("./test.txt", O_RDONLY);

	char *str;

	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		if (!str)
			break;
	}

	return (0);
}