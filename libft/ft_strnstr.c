/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:55 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 15:54:24 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{ 
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + ft_strlen(needle) < len + 1)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	haystack[] = "stackofhay";
	char	needle[] = "stack";

	printf("ft_strnstr: %s\n", ft_strnstr(haystack, needle, 3));
	printf("strnstr: %s\n", strnstr(haystack, needle, 3));
}
*/