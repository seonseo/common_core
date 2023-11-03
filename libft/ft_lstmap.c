/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:16:29 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/03 11:28:14 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_makelst(size_t size)
{
	t_list	*start;
	t_list	*now;

	if (size == 0)
		return (NULL);
	start = ft_lstnew(NULL);
	if (start == NULL)
		return (NULL);
	now = start;
	while (size)
	{
		now->next = ft_lstnew(NULL);
		if (now->next == NULL)
			ft_lstclear(&start);
		now = now->next;
		now->content = NULL;
		size--;
	}
	return (start);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	size;
	t_list	*newlst;

	size = ft_lstsize(lst);
}
