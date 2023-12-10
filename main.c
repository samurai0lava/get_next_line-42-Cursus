#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("Lorem", O_RDONLY);

	char *line;
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	char *line2;
	line2 = get_next_line(fd);
	printf("%s\n", line2);
	free(line2);
	char *line3;
	line3 = get_next_line(fd);
	printf("%s\n", line3);
	free(line3);
	// char *line4;
	// line4 = get_next_line(fd);
	// printf("%s\n", line4);	
	// free(line4);

}