#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include "libft/libft.h"

int	main(void)
{
	char	*endptr;

	printf("%ld\n", strtol("-9223372036854775808", &endptr, 10));
	printf("%s\n", strerror(errno));
	printf("%s\n", endptr);
	printf("%ld\n", ft_strtol("-9223372036854775808", &endptr, 10));
	printf("%s\n", strerror(errno));
	printf("%s\n", endptr);
}
