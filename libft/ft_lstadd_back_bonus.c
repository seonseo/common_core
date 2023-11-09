/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:05:20 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/09 10:42:42 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdio.h>

// static void    ft_print_result(t_list *elem)
// {
// 	int	len;

// 	len = 0;
// 	while (((char *)elem->content)[len])
// 			len++;
// 	write(1, elem->content, len);
// 	write(1, "\n", 1);
// }

// int main(void)
// {
// 	t_list          *begin;
// 	t_list          *elem;
// 	t_list          *elem2;
// 	t_list          *elem3;
// 	t_list          *elem4;
// 	char            *str = strdup("lorem");
// 	char            *str2 = strdup("ipsum");
// 	char            *str3 = strdup("dolor");
// 	char            *str4 = strdup("sit");

// 	elem = ft_lstnew(str);
// 	elem2 = ft_lstnew(str2);
// 	elem3 = ft_lstnew(str3);
// 	elem4 = ft_lstnew(str4);
// 	if (!elem || !elem2 || !elem3 || !elem4)
// 		return (0);
// 	begin = NULL;
// 	printf("%p\n", ft_lstlast(begin));
// 	ft_lstadd_back(&begin, elem);
// 	printf("%p\n", ft_lstlast(begin));
// 	ft_lstadd_back(&begin, elem2);
// 	printf("%p\n", ft_lstlast(begin));
// 	ft_lstadd_back(&begin, elem3);
// 	printf("%p\n", ft_lstlast(begin));
// 	ft_lstadd_back(&begin, elem4);
// 	printf("%p\n", ft_lstlast(begin));
// 	while (begin)
// 	{
// 		ft_print_result(begin);
// 		begin = begin->next;
// 	}
// 	return (0);
// }
