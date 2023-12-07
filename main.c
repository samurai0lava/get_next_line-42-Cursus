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
	char *line2 = get_next_line(fd);
	printf("%s\n", line2);
	free(line2);
}