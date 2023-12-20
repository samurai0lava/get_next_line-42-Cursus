/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:58:41 by iouhssei          #+#    #+#             */
/*   Updated: 2023/12/19 20:58:44 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0 ;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	line = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!line)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i] != '\0')
			line[i] = stash[i];
	while (buffer[j] != '\0')
		line[i++] = buffer[j++];
	line[ft_strlen(stash) + ft_strlen(buffer)] = '\0';
	free(stash);
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *)&s[i]);
	return (NULL);
}

char	*free_null(char *content)
{
	free(content);
	return (NULL);
}
