/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:43:39 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/09 11:01:35 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printlst(t_list *lst);

static t_list	*ft_makelst(size_t size, char **strs)
{
	t_list	*head;
	t_list	*tail;
	size_t	i;

	head = NULL;
	i = 0;
	while (i < size)
	{
		if (head == NULL)
		{
			head = ft_lstnew(strs[i]);
			if (head == NULL)
				return (NULL);
			tail = head;
		}
		else
		{
			tail->next = ft_lstnew(strs[i]);
			if (tail->next == NULL)
			{
				ft_lstclear(&head, free);
				return (NULL);
			}
			tail = tail->next;
		}
		i++;
	}
	return (head);
}

static void	del(void *p)
{
	free(p);
}

static void	*f(void *p)
{
	char	*str;

	if (p == NULL)
		return NULL;
	str = p;
	while (*str)
	{
		if (ft_isalnum(p))
			*str = '0';
		str++;
	}
}


int	main(void)
{
	char	**strs;
	list_t	*newlst;
	list_t	*lst;

	strs = ft_split("pain in my wrist", ' ');
	if (strs == NULL)
		return (1);
	lst = ft_makelst(4, strs);
	ft_printlst(lst);
	newlst = ft_lstmap(strs, f, del);
	ft_printlst(newlst);
}
