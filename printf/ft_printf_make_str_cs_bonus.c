/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_str_cs_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:23:44 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/15 19:52:50 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_make_str_c(t_format *spec, char c)
{
	*spec = (t_format){};
	write(1, &c, 1);
	return (ft_printf_make_str_spec(spec));
}

int	ft_printf_make_str_s(t_format *spec, char *s)
{
	*spec = (t_format){};
	if (NULL == s)
		return (write(1, "(null)", 6));
	spec->str_len = ft_strlen(s);
	write(1, s, spec->str_len);
	return (ft_printf_make_str_spec(spec));
}
