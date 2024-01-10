#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	a;
	int	printbyte;

	a = -10;
	printbyte = ft_printf("%d", a);
	printf("\npb:%d\n", printbyte);
	printbyte = printf("%d", a);
	printf("\npb:%d\n", printbyte);
	return (0);
}
