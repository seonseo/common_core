/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:04:37 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 15:36:03 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_ptr;

	b_ptr = (unsigned char *)b;
	while (len--)
		*b_ptr++ = c;
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[42] = {"00000000000000000000"};

	printf("%s\n", str);
	memset(str + 3, 'a', -3);
	ft_memset(str + 3, 'a', -3);
	printf("%s\n", str);
}
*/