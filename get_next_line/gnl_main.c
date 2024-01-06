#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("giant_line_nl.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
