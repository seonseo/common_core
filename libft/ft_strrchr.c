/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:30:29 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/17 21:15:17 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*lastchr;

	lastchr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			lastchr = (char *)s + i;
		i++;
	}
	if ('\0' == c)
		return ((char *)s + i);
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
