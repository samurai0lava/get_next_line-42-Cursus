    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:01:07 by iouhssei          #+#    #+#             */
/*   Updated: 2023/12/06 17:01:09 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i;
    char *buff;
    static char *content;
    int j;
    char *line;
    char *tmp;

    j = 0;
    i = 0;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    buff[BUFFER_SIZE] = '\0'; 

    int bytesRead;
    while (buff && (bytesRead = read(fd, buff, BUFFER_SIZE)) > 0 )
    {
        buff[bytesRead] = '\0'; 
        tmp = ft_strjoin(content, buff);
        free(content);
        content = tmp; 
        while (buff[i] != '\0' && buff[i] != '\n')
            i++;
        // if (buff[i] == '\n' || buff[i] == '\0')
        //     break;
        i = 0; 
    }
    free(buff);
    line = malloc(sizeof(char) * (j + 1));
    i = 0;
    while (content[i] != '\n' && content[i] != '\0')
    {
        line[j] = content[i];
        j++;
        i++;
    }
    line[j] = '\0';
    content = backup(content);
    return (line);
}
