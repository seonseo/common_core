#include "pipex.h"

int	main(int argc, char *argv[])
{
	int		pfd[2];
	int		i;

	if (argc != 5)
		usage_err("file1 cmd1 cmd2 file2");
	if (pipe(pfd) == -1)
		err_exit("pipe");
	pipex_fork(pfd, argv);
	i = 0;
	while (i < 2)
		if (close(pfd[i]) == -1)
			err_exit("close");
	i = 0;
	while(i < 2)
		if (wait(NULL) == -1)
			err_exit("wait");
	exit(EXIT_SUCCESS);
}

void	pipex_fork(char *argv[], int pfd[2])
{
	int	pid;
	int	i;

	i = 0;
	while (i < 2)
	{
		pid = fork();
		if (pid == -1)
			err_exit("fork");
		else if (pid == 0)
			pipex_child(pfd, argv, i);
	}
}

void	pipex_child(char *argv[], int pfd[2], int i)
{
	if (i == 0)
		pipex_child_left(pfd, argv[0]);
	else
		pipex_child_right(pfd, argv[4]);
	pipex_exec(argv, i);
}

void	pipex_child_left(int pfd[2], char *infile)
{
	int	infile_fd;

	if (close(pfd[0]) == -1)
		err_exit("close");
	if (pfd[1] != STDOUT_FILENO)
	{
		if (dup2(pfd[1], STDOUT_FILENO) == -1)
			err_exit("dup2");
		if (close(pfd[1]) == -1)
			err_exit("close");
	}
	infile_fd = open(infile, O_CREAT | O_RDONLY, (mode_t)777);
	if (infile_fd == -1)
		err_exit("open");
	if (infile_fd != STDIN_FILENO)
	{
		if (dup2(infile_fd, STDIN_FILENO) == -1)
			err_exit("dup2");
		if (close(infile_fd) == -1)
			err_exit("close");
	}
}

void	pipex_child_right(int pfd[2], char *outfile)
{
	int	outfile_fd;

	if (close(pfd[1]) == -1)
		err_exit("close");
	if (pfd[0] != STDIN_FILENO)
	{
		if (dup2(pfd[0], STDIN_FILENO) == -1)
			err_exit("dup2");
		if (close(pfd[0]) == -1)
			err_exit("close");
	}
	outfile_fd = open(outfile, O_CREAT | O_RDONLY, (mode_t)777);
	if (outfile_fd == -1)
		err_exit("open");
	if (outfile_fd != STDOUT_FILENO)
	{
		if (dup2(outfile_fd, STDOUT_FILENO) == -1)
			err_exit("dup2");
		if (close(outfile_fd) == -1)
			err_exit("close");
	}
}

void	pipex_exec(char *argv[], int i)
{
	char	**child_argv;

	child_argv = ft_split(argv[2 + i], ' ');
	if (child_argv == NULL)
		
	if (ft_execvp(child_argv[]) == -1)
		err_exit("ft_execvp");
}
