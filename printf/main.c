#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char	*a;
	int	printbyte;
	char *input = "|%10.3s|";

	a = "apple";
	printbyte = ft_printf(input, a);
	printf("\nprintbyte:%d\n\n", printbyte);
	printbyte = printf(input, a);
	printf("\nprintbyte:%d\n", printbyte);
	return (0);
}
//" %x ", LONG_MIN
//" %x ", ULONG_MAX
//" %x ", 9223372036854775807LL
//" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)
