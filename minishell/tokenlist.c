/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:59:38 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/11 21:43:42 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_tokenlist	*new_tokenlist(void)
{
	t_tokenlist	*tokenlist;

	tokenlist = (t_tokenlist *)malloc(sizeof(t_tokenlist));
	if (tokenlist == NULL)
		return (NULL);
	*tokenlist = (t_tokenlist){};
	return (tokenlist);
}

t_token	*new_token(t_tokentype type, char *str)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	*new_token = (t_token){};
	new_token->type = type;
	new_token->str = str;
	return (new_token);
}

int	tokenlist_add(t_tokenlist *tokenlist, t_token *token)
{
	if (token == NULL)
		return (-1);
	if (tokenlist->head == NULL)
	{
		tokenlist->head = token;
		tokenlist->back = token;
	}
	else
	{
		tokenlist->back->next = token;
		token->prev = tokenlist->back;
		tokenlist->back = token;
	}
	(tokenlist->size)++;
	return (0);
}

void	tokenlist_clear(t_tokenlist *tokenlist)
{
	t_token	*curr;
	t_token	*prev;

	if (tokenlist == NULL)
		return ;
	prev = NULL;
	curr = tokenlist->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev->str);
		prev->str = NULL;
		free(prev);
	}
	prev = NULL;
	free(tokenlist);
	tokenlist = NULL;
}
