#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "libft/libft.h"

int	main(void)
{
	char *endptr;

	printf("%ld\n", ft_strtol("-9999999999999999999999999999999999", &endptr, 10));
	printf("%s\n", strerror(errno));
	printf("%s\n", endptr);
}
