/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_execute_pipeline.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/24 21:41:57 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_pipeline(int argc, char *argv[])
{
	int		pfd_0[2];
	int		pfd_1[2];
	int		pid;
	int		i;

	i = 0;
	while (i < argc - 3)
	{
		create_pipe(argc, i, pfd_0);
		pid = safe_fork();
		if (pid == 0)
		{
			if (i == 0)
				pipex_child_left(pfd_0, argv[1]);
			else if (i < argc - 4)
				pipex_child_middle(pfd_0, pfd_1);
			else
				pipex_child_right(pfd_1, argv[argc - 1], FALSE);
			pipex_exec(argv, i, FALSE);
		}
		close_pipes(argc, pfd_0, pfd_1, i);
		pfd_1[0] = pfd_0[0];
		i++;
	}
	close(pfd_0[0]);
}

void	create_pipe(int argc, int i, int pfd[2])
{
	int	command_count;

	ft_dprintf(2, "create_pipe %d\n", i);
	command_count = argc - 3;
	if (i < command_count - 1 && pipe(pfd) == -1)
		err_exit("pipe");
}

int	safe_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		err_exit("fork");
	return (pid);
}

void	pipex_exec(char *argv[], int i, t_bool here_doc)
{
	char	**child_argv;

	ft_dprintf(2, "exec\n");
	if (here_doc == FALSE)
		child_argv = ft_split(argv[2 + i], ' ');
	else
		child_argv = ft_split(argv[3 + i], ' ');
	if (child_argv == NULL)
		err_exit("ft_split");
	if (ft_execvp(child_argv[0], child_argv) == -1)
		err_exit("ft_execvp");
}

void	close_pipes(int argc, int pfd_0[2], int pfd_1[2], int i)
{
	int	command_count;

	ft_dprintf(2, "close_pipes %d\n", i);
	command_count = argc - 3;
	if (i < command_count - 1 && close(pfd_0[1]) == -1)
		err_exit("close_pipes 1");
	if (i != 0 && close(pfd_1[0]) == -1)
		err_exit("close_pipes 2");
}
