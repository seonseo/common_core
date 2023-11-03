/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:54:30 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/03 14:59:08 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

#include <stdio.h>

int	main(void)
{
	char dst[] = "veryverykindperson";
	char src[] = "apple";

	printf("dst:%s\n", dst);
	printf("src:%s\n", src);
	ft_memcpy(NULL, NULL, 3);
	printf("dst:%s\n", dst);
}
