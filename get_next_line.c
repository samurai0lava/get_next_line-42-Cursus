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

// static char  *rest(char *str)
// {
// 	char *backup;
// 	size_t i;
// 	size_t j;

// 	i = 0;
// 	j = 0;

// 	while(str[i] != '\n' && str[i] != '\0')
// 		i++;
// 	i++;	
// 	backup = malloc(sizeof(char) * ft_strlen(str) + 1);
// 	if(!backup)
// 		return(NULL);
// 	while(str[i])
// 		backup[j++] = str[i++];
// 	backup[j] = '\0';
// 	free(str);
// 	if (backup[0] == '\0')
// 	{
// 		free(backup);
// 		return(NULL);
// 	}

// 	return(backup);
// }
static char	*ft_backup(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	line = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!line)
	{
		free (stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		line[j++] = stash[i++];
	line[j] = '\0';
	free(stash);
	return (line);
}

char *get_next_line(int fd)
{
    int i;
    char *buff;
    static char *content;

    char *line;
    char *tmp;
    int bytesRead;

    if(fd < 0 || BUFFER_SIZE < 0 || read(fd, buff, 0) < 0)
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
    //if found an empty string in the end of the file
    if (bytesRead == 0 && !content)
    {
        return (NULL);
        free(content);
    }

    while (content[i] != '\n' && content[i] != '\0')
        i++;
    line = malloc(sizeof(char) * (i + 1));
    i = 0;

    while (content[i] != '\n' && content[i] != '\0')
    {
        line[i] = content[i];
        i++;
    }
    line[i] = '\0';
    content = ft_backup(content);
    return (line);
}
    