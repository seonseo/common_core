/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:26:09 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/20 11:39:27 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(unsigned char *)s = 0;
		s++;
		n--;
	}
}

#include <stdio.h>

int	main(void)
{
	unsigned char str[42] = {"00000000000000000000"};
	int	i;

	printf("%s\n", str);
	ft_bzero(str + 3, 10);
	printf("%s\n", str);
	i = 0;
	while (i < 42)
	{
		printf("%d, ", str[i]);
		i++;
	}
	return (0);
}

