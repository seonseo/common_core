/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:19:24 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/20 11:41:30 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if ('\0' == c)
		return ((char *)s + i);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "ontorld";

	printf("%p\n%p\n%s\n", str, ft_strchr(str, '\0'), ft_strchr(str, '\0'));
}
*/