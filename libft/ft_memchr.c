/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:24:37 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/20 11:39:43 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == c)
			return ((void *)s + i);
		i++;
	}
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
