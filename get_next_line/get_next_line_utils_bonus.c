/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:03:31 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/03 21:38:58 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (src == NULL)
		return (0);
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

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	size = ft_strlen(s + start) + 1;
	if (size - 1 > len)
		size = len + 1;
	substr = (char *)malloc(sizeof(char) * size);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], size);
	return (substr);
}

int	ft_bufjoin(t_fdlist *fdnode, char *buf)
{
	char	*joinstr;
	size_t	joinlen;

	joinlen = fdnode->save_len + ft_strlen(buf);
	if (fdnode->save_size < joinlen + 1)
	{
		if (fdnode->save_size == 0)
			fdnode->save_size = joinlen + 1;
		while (fdnode->save_size < joinlen + 1)
			fdnode->save_size *= 2;
		joinstr = (char *)malloc(sizeof(char) * fdnode->save_size);
		if (joinstr == NULL)
			return (-1);
		ft_strlcpy(joinstr, fdnode->save, fdnode->save_size);
		free(fdnode->save);
		fdnode->save = joinstr;
	}
	ft_strlcpy(fdnode->save + fdnode->save_len, buf, fdnode->save_size);
	fdnode->save_len = joinlen;
	return (0);
}