#include "minishell.h"

int	main(void)
{
	t_tokenlist	*tokenlist;

	tokenlist = tokenizer(" sdfd>> er><<>|<>| ");
	print_tokenlist(tokenlist);
	ft_printf("size: %d\n", tokenlist->size);
	tokenlist_clear(tokenlist);
}
