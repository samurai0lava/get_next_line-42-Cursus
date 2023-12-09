#include "get_next_line.h"



size_t ft_strlen(char *str)
{
	size_t i;

	i = 0 ;
	while(str[i] != '\0')
		i++;
	return(i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*dst;	

	dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}


char *backup(char *str)
{
	char *backup;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	backup = malloc(sizeof(char) * ft_strlen(str) + 1);
	if(!backup)
		return(NULL);
	while(str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}