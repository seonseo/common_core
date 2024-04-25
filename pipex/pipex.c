/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:56 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 23:02:35 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		pfd[2];
	int		i;

	if (argc != 5)
		usage_err("file1 cmd1 cmd2 file2");
	if (pipe(pfd) == -1)
		err_exit("pipe");
	pipex_fork(argv, envp, pfd);
	i = 0;
	while (i < 2)
	{
		if (close(pfd[i]) == -1)
			err_exit("close 1");
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (wait(NULL) == -1)
			err_exit("wait");
		i++;
	}
	exit(EXIT_SUCCESS);
}

void	pipex_fork(char *argv[], char *envp[], int pfd[2])
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
		{
			if (i == 0)
				pipex_child_left(pfd, argv[1]);
			else
				pipex_child_right(pfd, argv[4]);
			pipex_exec(argv, envp, i);
		}
		i++;
	}
}

void	pipex_child_left(int pfd[2], char *infile)
{
	int	infile_fd;

	if (close(pfd[0]) == -1)
		err_exit("close 2");
	if (dup2(pfd[1], STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd[1]) == -1)
		err_exit("close 3");
	infile_fd = open(infile, O_RDONLY, (mode_t)0777);
	if (infile_fd == -1)
		err_exit("open 1");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(infile_fd) == -1)
		err_exit("close 4");
}

void	pipex_child_right(int pfd[2], char *outfile)
{
	int	outfile_fd;

	if (close(pfd[1]) == -1)
		err_exit("close 5");
	if (dup2(pfd[0], STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd[0]) == -1)
		err_exit("close 6");
	outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, (mode_t)0777);
	if (outfile_fd == -1)
		err_exit("open 2");
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(outfile_fd) == -1)
		err_exit("close 7");
}

void	pipex_exec(char *argv[], char *envp[], int i)
{
	char	**child_argv;

	child_argv = ft_split(argv[2 + i], ' ');
	if (child_argv == NULL)
		err_exit("ft_split");
	if (ft_execvpe(child_argv[0], child_argv, envp) == -1)
		err_exit("ft_execvp");
}
