#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int	a;
	int	printbyte;

	a = 42;
	printbyte = ft_printf("% 0.7d", a);
	printf("\npb:%d\n", printbyte);
	printbyte = printf("% 0.7d", a);
	printf("\npb:%d\n", printbyte);
	return (0);
}
//" %x ", LONG_MIN
//" %x ", ULONG_MAX
//" %x ", 9223372036854775807LL
//" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)
