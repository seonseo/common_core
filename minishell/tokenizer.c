/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:53:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/10 22:24:25 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokenlist	*tokenizer(const char *input)
{
	t_tokenlist	*tokenlist;
	t_tokentype	tokentype;
	t_quotetype	quotetype;
	size_t		tok_start;
	size_t		i;

	if (input == NULL)
		return (NULL);
	tokenlist = (t_tokenlist *)malloc(sizeof(t_tokenlist));
	*tokenlist = (t_tokenlist){};
	quotetype = NO_QUOTE;
	tokentype = TOK_UNKNOWN;
	i = 0;
	while (input[i])
	{
		if (tokentype == TOK_OPERATOR && \
			!is_part_of_operator(input, tok_start, i))
		{
			tokenlist_add(tokenlist, new_token(tokentype, \
			ft_substr(input, tok_start, i - tok_start)));
		}
		if (is_operator(input[i]))
		{
			if (!is_part_of_operator(input, tok_start, i))
			{
				tokenlist_add(tokenlist, new_token(tokentype, \
				ft_substr(input, tok_start, i - tok_start)));
			}
			if (tokentype != TOK_OPERATOR)
			{
				tokentype = TOK_OPERATOR;
				tok_start = i;
			}
		}
		else if (input[i] == '\'' && quotetype != DOUBLE_QUOTE)
		{
			if (quotetype == NO_QUOTE)
				quotetype = SINGLE_QUOTE;
			else
				quotetype = NO_QUOTE;
			if (tokentype != TOK_WORD)
			{
				tokentype = TOK_WORD;
				tok_start = i;
			}
		}
		else if (input[i] == '\"' && quotetype != SINGLE_QUOTE)
		{
			if (quotetype == NO_QUOTE)
				quotetype = DOUBLE_QUOTE;
			else
				quotetype = NO_QUOTE;
			if (tokentype != TOK_WORD)
			{
				tokentype = TOK_WORD;
				tok_start = i;
			}
		}
		else if (ft_isspace(input[i]) && quotetype == NO_QUOTE)
		{
			if (i > 0 && tokentype != TOK_UNKNOWN)
				tokenlist_add(tokenlist, new_token(tokentype, \
				ft_substr(input, tok_start, i - tok_start)));
			tokentype = TOK_UNKNOWN;
		}
		else if (tokentype == TOK_UNKNOWN)
		{	
			tok_start = i;
			tokentype = TOK_WORD;
		}
		i++;
	}
	if (tokentype != TOK_UNKNOWN)
		tokenlist_add(tokenlist, new_token(tokentype, \
		ft_substr(input, tok_start, i - tok_start)));
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

void	tokenlist_add(t_tokenlist *tokenlist, t_token *token)
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

int	is_operator(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	is_part_of_operator(const char *input, size_t tok_start, size_t i)
{
	int	len;

	len = i - tok_start + 1;
	if (len == 2)
	{
		if (ft_strncmp("<<", &input[tok_start], len) == 0 || \
			ft_strncmp(">>", &input[tok_start], len) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	print_tokenlist(t_tokenlist *tokenlist)
{
	t_token	*curr;

	curr = tokenlist->head;
	while (curr)
	{
		if (ft_printf("%d: %s\n", curr->type, curr->str) == -1)
			return (-1);
		curr = curr->next;
	}
	return (0);
}
