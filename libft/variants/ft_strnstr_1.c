/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:55 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 15:55:30 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*haystack_p;
	const char	*needle_p;

	haystack_p = haystack;
	needle_p = needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && ft_strlen(needle) < ((len--) + 1))
	{
		if (*haystack == *needle)
		{
			haystack_p = haystack;
			needle_p = needle;
			while (*haystack_p && *haystack_p == *needle_p)
			{
				haystack_p++;
				needle_p++;
			}
			if (*needle_p == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	haystack[] = "stackofhay";
	char	needle[] = "ofh";

	printf("ft_strnstr: %s\n", ft_strnstr(haystack, needle, 1));
	printf("strnstr: %s\n", strnstr(haystack, needle, 1));
}
*/