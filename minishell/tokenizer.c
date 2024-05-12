/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:53:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/12 13:33:39 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_tokenlist	*tokenizer(const char *input)
{
	t_tokenlist	*tokenlist;

	if (input == NULL)
		return (NULL);
	tokenlist = new_tokenlist();
	if (tokenlist == NULL)
		tokenizer_err_exit(NULL, "tokenlist allocation fail");
	process_tokens(input, tokenlist);
	return (tokenlist);
}

void	process_tokens(const char *input, t_tokenlist *tokenlist)
{
	t_tokentype				tokentype;
	t_quotetype				quotetype;
	size_t					tok_start;
	size_t					i;
	t_token_handler_args	args;

	quotetype = NO_QUOTE;
	tokentype = TOK_UNKNOWN;
	args = (t_token_handler_args){input, &tok_start, \
			&tokentype, &quotetype, tokenlist};
	i = 0;
	while (input[i])
	{
		handle_token_creation(&args, i);
		i++;
	}
	if (quotetype != NO_QUOTE)
		tokenizer_err_exit(tokenlist, "unclosed quotation detected");
	else if (tokentype != TOK_UNKNOWN)
		if (tokenlist_add(tokenlist, new_token(tokentype, \
		ft_substr(input, tok_start, i - tok_start))) == -1)
			tokenizer_err_exit(tokenlist, "token allocation fail");
}

void	handle_token_creation(t_token_handler_args *args, size_t i)
{
	if (is_operator((args->input)[i]) && *(args->quotetype) == NO_QUOTE)
		handle_operator(args, i);
	else if (ft_isspace((args->input)[i]) && *(args->quotetype) == NO_QUOTE)
		handle_space(args, i);
	else
		handle_word(args, i);
}

void	tokenizer_err_exit(t_tokenlist *tokenlist, char *err_msg)
{
	if (tokenlist != NULL)
		tokenlist_clear(tokenlist);
	perror(err_msg);
	exit(EXIT_FAILURE);
}

int	print_tokenlist(t_tokenlist *tokenlist)
{
	t_token	*curr;

	curr = tokenlist->head;
	while (curr)
	{
		if (ft_printf("%d:%s\n", curr->type, curr->str) == -1)
			return (-1);
		curr = curr->next;
	}
	return (0);
}

int	main(void)
{
	t_tokenlist	*tokenlist;

	tokenlist = tokenizer(" asd|sdf\"d<<<'s' f\" ><< f ");
	print_tokenlist(tokenlist);
	ft_printf("size:%d\n", tokenlist->size);
	tokenlist_clear(tokenlist);
}
