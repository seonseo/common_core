#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include "libft/libft.h"

int	main(void)
{
	printf("%ld\n", strtol("-9223372036854775808", NULL, 10));
	printf("%s\n", strerror(errno));
	printf("%ld\n", ft_strtol("-9223372036854775808", NULL, 10));
	printf("%s\n", strerror(errno));
}
