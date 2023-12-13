#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int main()
{

    clock_t begin = clock();    

//**************************************************************************** */ 
    int fd;
    fd = open("giant_line_nl.txt", O_RDONLY | O_APPEND| O_CREAT, 0666);

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
//**************************************************************************** */  
   
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
   
    return 0;
}