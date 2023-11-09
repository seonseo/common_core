/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:26:46 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/08 09:07:54 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		del(prev->content);
		free(prev);
	}
}
