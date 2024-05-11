/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:31:34 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/11 22:49:51 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	main(void)
{
	t_tokenlist	*tokenlist;

	tokenlist = tokenizer(" asd|sdf\"d<<<'s' f\" ><< f ");
	print_tokenlist(tokenlist);
	ft_printf("size:%d\n", tokenlist->size);
	tokenlist_clear(tokenlist);
}
