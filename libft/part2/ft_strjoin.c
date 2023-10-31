/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:42:23 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/27 11:28:20 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "happy happy ";
	char	s2[] = "";
	char	*str;

	str = ft_strjoin(s1, s2);
	if (str == NULL)
		return (1);
	printf("%s\n", str);
	printf("%zu\n", ft_strlen(str));
}
*/