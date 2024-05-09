/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:53:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/09 22:35:05 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef enum e_tokentype
{
	TOK_UNKNOWN,
	TOK_WORD,
	TOK_OPERATOR
}	t_tokentype;

typedef struct s_token
{
	t_tokentype		type;
	char			*str;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_tokenlist
{
	size_t	size;
	t_token	*head;
	t_token	*back;
}	t_tokenlist;

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

void	tokenlist_add_back(t_tokenlist *tokenlist, t_token *token)
{
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
}

void	tokenlist_clear(t_tokenlist *tokenlist)
{
	t_token	*curr;
	t_token	*prev;

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

int	is_operator()
{
	
}

t_tokenlist	*recognize_token(const char *input)
{
	t_tokenlist	*tokenlist;
	t_tokentype	tokentype;
	size_t		tok_start;
	size_t		i;

	tokentype = TOK_UNKNOWN;
	i = 0;
	while (input[i])
	{
		
		i++;
	}

	
}
