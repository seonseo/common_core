/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:30:29 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 15:53:46 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*lastchr;

	lastchr = NULL;
	while (*s)
	{
		if (*s == c)
			lastchr = (char *)s;
		s++;
	}
	if ('\0' == c)
		return ((char *)s);
	return (lastchr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "ontopoftheworld";

	printf("%s\n", ft_strrchr(str, 'p'));
}
*/
