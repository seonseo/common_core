/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:31:57 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 14:47:36 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (0 < dstsize)
	{
		while (*src && 1 < dstsize--)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	char	str[] = "0123456789abcdef";
	size_t	dst_len = 10;

	ft_strlcpy(dst, str, 5);
	printf("%s\n", dst);

	for (size_t i = 0; i < dst_len; i++)
	{
		printf("%d", dst[i]);
		if (i + 1 < dst_len)
			printf(", ");
	}
}
*/