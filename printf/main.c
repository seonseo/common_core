/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:16:11 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/16 20:12:50 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int		printbyte;
	int		a;
	char	*input;

	input = "^.^/%#48.54x^.^/";
	a = 0;
	printbyte = ft_printf(input, a);
	printf("\nprintbyte:%d\n\n", printbyte);
	printbyte = printf(input, a);
	printf("\nprintbyte:%d\n", printbyte);
	return (0);
}
