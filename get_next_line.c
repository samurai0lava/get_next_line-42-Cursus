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


// char	*get_next_line(int fd)
// {
// 	int			i;
// 	char 		*buff;
// 	static char	*content;
// 	int			j;
// 	char		*line;

// 	j = 0;
// 	i = 0;
// 	buff = malloc(sizeof(char)* BUFF_SIZE + 1);
// 	while(buff[i] != '\0' || buff[i] != '\n')
// 	{
// 		read(fd, buff, BUFF_SIZE);
// 		content = ft_strjoin(buff, content);
// 		i++;
// 	}
// 	free(buff);
// 	line = malloc(sizeof(char) * ft_line_len(content) + 1);
// 	i = 0;
// 	while(content[i] != '\n')
// 		line[j++] = content[i++];
// 	free(content);
// 	content = ft_strjoin(rest(content), content);
// 	return(line);
// }

#include "get_next_line.h"

// char *get_next_line(int fd)
// {
//     int i;
//     char *buff;
//     static char *content;
//     int j;
//     char *line;

//     j = 0;
//     i = 0;
//     buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
//     buff[BUFF_SIZE] = '\0'; // Initialize the last character to null

//     while (read(fd, buff, BUFF_SIZE) > 0)
//     {
//         content = ft_strjoin(buff, content);
//         while (buff[i] != '\0' && buff[i] != '\n')
//         {
//             i++;
//         }
//         if (buff[i] == '\n')
//         {
//             break; // Exit the loop if newline is found
//         }
//         i = 0; // Reset i for the next iteration
//     }
//     free(buff);

//     line = malloc(sizeof(char) * (ft_line_len(content) + 1));
//     i = 0;
//     while (content[i] != '\n' && content[i] != '\0')
//     {
//         line[j] = content[i];
//         j++;
//         i++;
//     }
//     line[j] = '\0';
//     free(content);
//     content = ft_strjoin(rest(content), content);

//     return line;
// }
#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i;
    char *buff;
    static char *content;
    int j;
    char *line;

    j = 0;
    i = 0;
    buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
    buff[BUFF_SIZE] = '\0'; // Initialize the last character to null

    int bytesRead;
    while ((bytesRead = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[bytesRead] = '\0'; // Null-terminate the buffer
        content = ft_strjoin(content, buff);
        while (buff[i] != '\0' && buff[i] != '\n')
            i++;
        if (buff[i] == '\n')
            break; // Exit the loop if newline is found
        i = 0; // Reset i for the next iteration
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
    free (content);
    content = ft_strjoin(rest(content), content);
    return (line);
}