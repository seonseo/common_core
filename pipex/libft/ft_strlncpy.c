/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:31:57 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/18 19:58:41 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlncpy(char *dst, const char *src, size_t dstsize, size_t n)
{
	size_t	i;

	if (0 == dstsize)
		return (0);
	i = 0;
	while (src[i] && i + 1 < dstsize && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] && i < n)
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	char	str[] = "0123456789abcdef";
	size_t	dst_len = 10;

	strlcpy(dst, str, 3);
	printf("%s\n", dst);

	for (size_t i = 0; i < dst_len; i++)
	{
		printf("%d", dst[i]);
		if (i + 1 < dst_len)
			printf(", ");
	}
}
*/
