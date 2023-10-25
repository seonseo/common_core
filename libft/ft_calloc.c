/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:44:09 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/24 16:43:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	
	mem = malloc(count * size);
	if (mem == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memset(mem, '\0', count * size);
	return (mem);
}
/*
#include <stdio.h>

int main(void)
{
	char	str[] = "I will be pirate king";
	char	*ptr;

	ptr = (char *)calloc(22, 1);
	ft_strlcpy(ptr, str, 22);
	printf("%s\n", ptr);
}
*/