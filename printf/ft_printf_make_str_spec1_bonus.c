/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_str_spec1_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:00:11 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/15 23:33:50 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_make_str_spec(t_format *spec)
{
	char	*str;
	size_t	i;

	str = ft_printf_make_str_malloc(spec);
	if (NULL == str)
		return (-1);
	i = 0;
	if (!flag_is_on(spec->flags, FLAG_MINUS) && !flag_is_on(spec->flags, FLAG_ZERO))
		ft_printf_make_str_width(spec, str, &i);
	ft_printf_make_str_prefix(spec, str, &i);
	ft_printf_make_str_precision(spec, str, &i);
	if (flag_is_on(spec->flags, FLAG_ZERO))
		ft_printf_make_str_width(spec, str, &i);
	ft_printf_make_str_cpy_num(spec, str, &i);
	if (flag_is_on(spec->flags, FLAG_MINUS))
		ft_printf_make_str_width(spec, str, &i);
	spec->str = str;
	return (0);
}
