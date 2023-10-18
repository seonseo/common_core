/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:55:49 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/17 21:22:04 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <stdio.h>

int	main(void)
{
	// char	s1[] = "apple";
	// char	s2[] = "apble";
	char	c1 = (char)(1);
	char	c2 = (char)(3);

	// printf("%d\n", ft_strncmp(s1, s2, 0));
	printf("%d, %d\n", c1, c2);
	printf("%d, %d\n", (unsigned char)c1, (unsigned char)c2);
	printf("%d\n", (unsigned char)c1 - (unsigned char)c2);
	printf("%d\n", (c1 - c2));
	printf("%d\n", (unsigned char)(c1 - c2));
}
