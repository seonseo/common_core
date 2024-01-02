/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:03:31 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/02 14:29:39 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ('\0' == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*str_dup;

	size = ft_strlen(s1) + 1;
	str_dup = (char *)malloc(sizeof(char) * size);
	if (str_dup == NULL)
		return (NULL);
	ft_strlcpy(str_dup, s1, size);
	return (str_dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (0 < dstsize)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (s == NULL || start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start) + 1;
	if (size - 1 > len)
		size = len + 1;
	substr = (char *)malloc(sizeof(char) * size);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], size);
	return (substr);
}