#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

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

t_tokenlist	*tokenizer(const char *input);
t_token		*new_token(t_tokentype type, char *str);
void		tokenlist_add(t_tokenlist *tokenlist, t_token *token);
void		tokenlist_clear(t_tokenlist *tokenlist);

int			is_operator(char c);
int			is_part_of_operator(const char *input, size_t tok_start, size_t i);
//debugging functions
int			print_tokenlist(t_tokenlist *tokenlist);

#endif
