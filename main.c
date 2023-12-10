#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    fd = open("Lorem", O_RDONLY);

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);

    return 0;
}
