/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_input_to_int_matrix1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:36:16 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/15 20:59:00 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_ptrslen(void **ptrs)
{
	size_t	len;

	len = 0;
	while (ptrs[len])
		len++;
	return (len);
}

int	*str_to_int_arr(char *str, int len)
{
	char	**nums_strs;
	int		*nums_int_arr;
	int		i;

	nums_strs = ft_split(str, ' ');
	nums_int_arr = (int *)malloc(sizeof(int) * len);
	if (NULL == nums_int_arr)
		exit_error("Error malloc for nums_int_arr", 1);
	i = 0;
	while (nums_strs[i])
	{
		nums_int_arr[i] = ft_atoi(nums_strs[i]);
		free(nums_strs[i]);
		i++;
	}
	free(nums_strs);
	return (nums_int_arr);
}
