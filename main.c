#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("Lorem", O_RDONLY);

	char *line;
	while ((line = get_next_line(fd)))
	{
		//printf("%s\n", line);
		free(line);
	}
}