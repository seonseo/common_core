/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:19:24 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/02 09:15:16 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ('\0' == c)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
		if (*s++ == c)
			return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "ontorld";

	printf("%p\n%p\n%p\n", str, ft_strchr(str, 'a'), ft_strchr(str, '\0'));
}
*/
