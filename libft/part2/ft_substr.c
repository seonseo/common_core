/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:12:14 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/24 17:52:01 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	size;

	size = ft_strlen(s + start) + 1;
	if (size > len + 1)
		size = len + 1;
	str_sub = (char *)malloc(sizeof(char) * size);
	ft_strlcpy(str_sub, s + start, size);
	return (str_sub);
}

int	main(void)
{
	char	str[] = "find a needle from haystack";
	char	*str_sub;

	str_sub = ft_substr(str, 7, 6);
	printf("%s\n", str_sub);
}

/*
parameters
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Return value
The substring.
NULL if the allocation fails.

external functs
malloc

Description
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
*/