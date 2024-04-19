#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "error_functions.h"

#define BUF_SIZE 10

int main(int argc, char **argv)
{
	int		pfd[2];
	char	buf[BUF_SIZE];
	ssize_t	num_read;

	if (argc != 2)
		usage_err("%s string\n", argv[0]);

	if (pipe(pfd) == -1)
		err_exit("pipe");

	switch (fork())
	{
	case -1:
		err_exit("fork");

	case 0:
		if (close(pfd[1]) == -1)
			err_exit("close - child");

		while (1)
		{
			num_read = read(pfd[0], buf, BUF_SIZE);
			if (num_read == -1)
				err_exit("read");
			if (num_read == 0)
				break;
			if (write(STDOUT_FILENO, buf, num_read) != num_read)
				fatal("child - partial/failed write");
		}

		write(STDOUT_FILENO, "\n", 1);
		if (close(pfd[0]) == -1)
			err_exit("close");
		_exit(EXIT_SUCCESS);

	default:
		if (close(pfd[0]) == -1)
			err_exit("close - parent");
		if (write(pfd[1], argv[1], strlen(argv[1])) != (ssize_t)strlen(argv[1]))
			fatal("parent - partial/failed write");

		if (close(pfd[1]) == -1)
			err_exit("close");
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
}
