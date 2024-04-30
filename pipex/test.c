#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errono.h>

int	main(void)
{
	printf("%ld\n", strtol("-9223372036854775808", NULL, 10));
	printf("%s\n", strerror(errno));
}
