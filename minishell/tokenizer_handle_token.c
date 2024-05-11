/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handle_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:57:36 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/11 22:48:40 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	handle_operator(t_token_handler_args *args, size_t i)
{
	if (*(args->tokentype) != TOK_OPERATOR)
	{
		if (*(args->tokentype) != TOK_UNKNOWN)
			if (tokenlist_add(args->tokenlist, new_token(*(args->tokentype), \
			ft_substr(args->input, *(args->tok_start), \
			i - *(args->tok_start)))) == -1)
				tokenizer_err_exit(args->tokenlist, "token allocation fail");
		*(args->tokentype) = TOK_OPERATOR;
		*(args->tok_start) = i;
	}
	else if (!is_part_of_operator(args->input, *(args->tok_start), i))
	{
		if (tokenlist_add(args->tokenlist, new_token(*(args->tokentype), \
		ft_substr(args->input, *(args->tok_start), \
		i - *(args->tok_start)))) == -1)
			tokenizer_err_exit(args->tokenlist, "token allocation fail");
		*(args->tok_start) = i;
	}
}

void	handle_space(t_token_handler_args *args, size_t i)
{
	if (i > 0 && *(args->tokentype) != TOK_UNKNOWN)
		if (tokenlist_add(args->tokenlist, new_token(*(args->tokentype), \
		ft_substr(args->input, *(args->tok_start), \
		i - *(args->tok_start)))) == -1)
			tokenizer_err_exit(args->tokenlist, "token allocation fail");
	*(args->tokentype) = TOK_UNKNOWN;
}

void	handle_word(t_token_handler_args *args, size_t i)
{
	if (*(args->tokentype) == TOK_OPERATOR)
	{
		if (tokenlist_add(args->tokenlist, new_token(*(args->tokentype), \
		ft_substr(args->input, *(args->tok_start), \
		i - *(args->tok_start)))) == -1)
			tokenizer_err_exit(args->tokenlist, "token allocation fail");
		*(args->tok_start) = i;
	}
	else if (*(args->tokentype) == TOK_UNKNOWN)
		*(args->tok_start) = i;
	*(args->tokentype) = TOK_WORD;
	if ((args->input)[i] == '\'' && *(args->quotetype) != DOUBLE_QUOTE)
	{
		if (*(args->quotetype) == NO_QUOTE)
			*(args->quotetype) = SINGLE_QUOTE;
		else
			*(args->quotetype) = NO_QUOTE;
	}
	else if ((args->input)[i] == '\"' && *(args->quotetype) != SINGLE_QUOTE)
	{
		if (*(args->quotetype) == NO_QUOTE)
			*(args->quotetype) = DOUBLE_QUOTE;
		else
			*(args->quotetype) = NO_QUOTE;
	}
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
