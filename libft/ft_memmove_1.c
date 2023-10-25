/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:32:53 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 10:44:31 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*original_dst;

	original_dst = dst;
	if (dst <= src)
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	else
		while (len--)
			*(unsigned char *)(dst + len)\
			= *(unsigned char *)(src + len);
	return (original_dst);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	unsigned char	board[] = "0123456789abcde";
	unsigned char	*dst = board;
	unsigned char	*src = board + 3;

	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("length : 6\n\n");

	printf("case 1: dst <= src\n");
	printf("memmove\n");
	memmove(dst, src, 6);
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);

	strcpy((char *)board, "0123456789abcde");
	printf("ft_memmove\n");
	ft_memmove(dst, src, 6);
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);

	strcpy((char *)board, "0123456789abcde");
	printf("\ncase 2: src < dst\n");
	dst = board + 3;
	src = board;

	printf("memmove\n");
	memmove(dst, src, 6);
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);

	strcpy((char *)board, "0123456789abcde");
	printf("ft_memmove\n");
	ft_memmove(dst, src, 6);
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
}

