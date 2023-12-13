













#include "get_next_line.h"

// size_t ft_strlen_new_line(char *str)
// {
// 	size_t i;

// 	i = 0 ;
// 	while(str[i] != '\n')
// 		i++;
// 	return(i);
// }
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
// char	*ft_strchr(const char *s, int c)
// {
// 	size_t			i;
// 	unsigned char	ch;

// 	ch = (unsigned char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == ch)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == ch)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }.