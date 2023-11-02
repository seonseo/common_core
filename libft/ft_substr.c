/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:12:14 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/27 16:50:38 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	size;

	if (start < ft_strlen(s))
	{
		size = ft_strlen(s + start) + 1;
		if (size > len + 1)
			size = len + 1;
	}
	else
		size = 1;
	str_sub = (char *)malloc(sizeof(char) * size);
	if (str_sub == NULL)
		return (NULL);
	ft_strlcpy(str_sub, s + start, size);
	return (str_sub);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "find";
	char	*str_sub;

	str_sub = ft_substr(str, 0, 1);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", str_sub[i]);
	}
	printf("\n%s\n", str_sub);
}
*/