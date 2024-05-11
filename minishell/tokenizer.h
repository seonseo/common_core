/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:17:36 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/11 22:52:09 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"
# include <stdio.h>

typedef enum e_tokentype
{
	TOK_UNKNOWN,
	TOK_WORD,
	TOK_OPERATOR
}	t_tokentype;

typedef enum e_quotetype
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_quotetype;

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

typedef struct s_token_handler_args
{
	const char	*input;
	size_t		*tok_start;
	t_tokentype	*tokentype;
	t_quotetype	*quotetype;
	t_tokenlist	*tokenlist;
}	t_token_handler_args;

//tokenizer.c
t_tokenlist	*tokenizer(const char *input);
void		process_tokens(const char *input, t_tokenlist *tokenlist);
void		handle_token_creation(t_token_handler_args *args, size_t i);
void		tokenizer_err_exit(t_tokenlist *tokenlist, char *err_msg);
//debugging functions
int			print_tokenlist(t_tokenlist *tokenlist);

//tokenlist.c
t_tokenlist	*new_tokenlist(void);
t_token		*new_token(t_tokentype type, char *str);
int			tokenlist_add(t_tokenlist *tokenlist, t_token *token);
void		tokenlist_clear(t_tokenlist *tokenlist);

//tokenizer_handle_token.c
void		handle_operator(t_token_handler_args *args, size_t i);
void		handle_space(t_token_handler_args *args, size_t i);
void		handle_word(t_token_handler_args *args, size_t i);
int			is_operator(char c);
int			is_part_of_operator(const char *input, size_t tok_start, size_t i);

#endif
