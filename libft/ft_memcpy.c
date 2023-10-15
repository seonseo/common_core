/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:54:30 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/15 18:32:33 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	char dst[42] = {"veryverykindperson"};
	char src[42] = "apple";

	printf("dst:%s\n", dst);
	printf("src:%s\n", src);
	ft_memcpy(dst, src, 3);
	printf("dst:%s\n", dst);
}
*/
