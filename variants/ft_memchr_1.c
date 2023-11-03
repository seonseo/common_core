/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:24:37 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 10:11:00 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*(unsigned char *)s++ == c)
			return ((void *)s);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[42] = "42seoul";

	printf("%s\n", (char *)ft_memchr(s, 'a', 4));
}
*/
