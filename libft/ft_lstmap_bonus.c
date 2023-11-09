/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:16:29 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/08 19:11:43 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_makelst(size_t size)
{
	t_list	*start;
	t_list	*now;

	if (size == 0)
		return (NULL);
	start = ft_lstnew(NULL);
	if (start == NULL)
		return (NULL);
	now = start;
	while (size - 1)
	{
		now->next = ft_lstnew(NULL);
		if (now->next == NULL)
		{
			ft_lstclear(&start, free);
			return (NULL);
		}
		now = now->next;
		size--;
	}
	return (start);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	size;
	t_list	*newlst;
	t_list	*now;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	newlst = ft_makelst(size);
	if (newlst == NULL)
		return (NULL);
	now = newlst;
	while (now)
	{
		now->content = f(lst->content);
		if (now->content == NULL)
		{
			ft_lstclear(&newlst, free);
			return (NULL);
		}
		lst = lst->next;
		now = now->next;
	}
	return (newlst);
}
