/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:55 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/18 15:10:04 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(const char *haystack, const char *needle)
{ 
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return (haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return (haystack + i);
		}
		i++;
	}
	return (NULL);
}
