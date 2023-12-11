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

static char  *rest(char *str)
{
	char *backup;
	size_t i;
	size_t j;

	i = 0;
	j = 0;

	while(str[i] != '\n' && str[i] != '\0')
		i++;
	i++;	
	backup = malloc(sizeof(char) * ft_strlen(str) + 1);
	if(!backup)
		return(NULL);
	while(str[i])
		backup[j++] = str[i++];
	backup[j] = '\0';
	free(str);
	if (backup[0] == '\0')
	{
		free(backup);
		return(NULL);
	}
	return(backup);
}

char *get_next_line(int fd)
{
    int i;
    char *buff;
    static char *content;
    int j;
    char *line;
    char *tmp;
    int bytesRead;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    buff[BUFFER_SIZE] = '\0';
    i = 0;
    while ((bytesRead = read(fd, buff, BUFFER_SIZE)) > 0 )
    {    
        if (bytesRead < 0)
            return (NULL);
        buff[bytesRead] = '\0'; 
        tmp = ft_strjoin(content, buff);
        free(content);
        content = tmp; 
        while (buff[i] != '\0' && buff[i] != '\n')
            i++;
        i = 0; 
    }
    free(buff);
    if (bytesRead == 0 && content == NULL)
    {
        return (NULL);
        free(content);
    }
    j = 0;
    while (content[j] != '\n' && content[j] != '\0')
        j++;
    line = malloc(sizeof(char) * (j + 1));
    i = 0;
    j = 0;
    while (content[i] != '\n' && content[i] != '\0')
    {
        line[j] = content[i];
        j++;
        i++;
    }
    line[j] = '\0';
    content = rest(content);
    return (line);
}
