#include "get_next_line.h"

int main ()
{

	int fd;
	//int line;
	char *buf;

	fd = open("test.txt", O_RDONLY);
	buf = get_next_line(fd);
	printf("\n%s", buf);
	free(buf);
	/*
	line = 0;
	while (line < 10)
	{
		buf = get_next_line(fd);
		printf("\n%s", buf);
		free(buf);
		line++;
	}*/
	close(fd);
	return (0);
}