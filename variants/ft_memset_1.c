/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:04:37 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 10:35:26 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*original_b;

	original_b = b;
	while (len--)
		*(unsigned char *)b++ = c;
	return (original_b);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[42] = {"00000000000000000000"};

	printf("%s\n", str);
	ft_memset(str + 3, 'a', 3);
	printf("%s\n", str);
}
*/
