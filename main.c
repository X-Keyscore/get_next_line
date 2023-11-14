#include "get_next_line.h"

int main ()
{
	int fd;
	char *buf;

	fd = open("big_line_no_nl", O_RDONLY);
	buf = get_next_line(fd);
	printf("result = |%s|\n", buf);
	free(buf);
	printf("=================\n");
	
	buf = get_next_line(fd);
	printf("result = |%s|\n", buf);
	free(buf);
	printf("=================\n");

	buf = get_next_line(fd);
	printf("result = |%s|\n", buf);
	free(buf);
	printf("=================\n");

	buf = get_next_line(fd);
	printf("result = |%s|\n", buf);
	free(buf);
	close(fd);
	return (0);
}