/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_execute_pipeline.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 22:59:54 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_pipeline(int argc, char *argv[], char *envp[], int cmd_cnt)
{
	int		pfd_0[2];
	int		pfd_1[2];
	int		pid;
	int		i;

	i = 0;
	while (i < argc - 3)
	{
		create_pipe(cmd_cnt, i, pfd_0);
		pid = safe_fork();
		if (pid == 0)
		{
			if (i == 0)
				pipex_child_left(pfd_0, argv[1]);
			else if (i < argc - 4)
				pipex_child_middle(pfd_0, pfd_1);
			else
				pipex_child_right(pfd_1, argv[argc - 1], FALSE);
			pipex_exec(argv, envp, i, FALSE);
		}
		close_pipes(cmd_cnt, i, pfd_0, pfd_1);
		pfd_1[0] = pfd_0[0];
		i++;
	}
}

void	create_pipe(int cmd_cnt, int i, int pfd_0[2])
{
	if (i < cmd_cnt - 1)
	{
		if (pipe(pfd_0) == -1)
			err_exit("pipe");
	}
}

int	safe_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		err_exit("fork");
	return (pid);
}

void	pipex_exec(char *argv[], char *envp[], int i, t_bool here_doc)
{
	char	**child_argv;

	if (here_doc == FALSE)
		child_argv = ft_split(argv[2 + i], ' ');
	else
		child_argv = ft_split(argv[3 + i], ' ');
	if (child_argv == NULL)
		err_exit("ft_split");
	if (ft_execvpe(child_argv[0], child_argv, envp) == -1)
		err_exit("ft_execvp");
}

void	close_pipes(int cmd_cnt, int i, int pfd_0[2], int pfd_1[2])
{
	if (i < cmd_cnt - 1)
	{
		if (close(pfd_0[1]) == -1)
			err_exit("close_pipes 1");
	}
	if (i != 0)
	{
		if (close(pfd_1[0]) == -1)
			err_exit("close_pipes 2");
	}
}
