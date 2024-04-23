/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_execute_pipeline.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/23 23:10:07 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_pipeline(int argc, char *argv[], t_bool here_doc)
{
	int		pfd_0[2];
	int		pfd_1[2];
	int		pid;
	int		i;

	i = 0;
	while (i < argc - 3)
	{
		create_pipe(argc, i, pfd_0);
		safe_fork(&pid);
		if (pid == 0)
		{
			if (i == 0)
				pipex_child_left(pfd_0, argv[1]);
			else if (i < argc - 4)
				pipex_child_middle(pfd_0, pfd_1);
			else
				pipex_child_right(pfd_1, argv[argc - 1], here_doc);
			pipex_exec(argv, i);
		}
		close_pipes(pfd_0, pfd_1, i);
		pfd_1[0] = pfd_0[0];
		i++;
	}
	close(pfd_0[0]);
}

void	create_pipe(int argc, int i, int pfd[2])
{
	if (i < argc - 2 && pipe(pfd) == -1)
		err_exit("pipe");
}

void	safe_fork(int *pid)
{
	*pid = fork();
	if (*pid == -1)
		err_exit("fork");
}

void	close_pipes(int pfd_0[2], int pfd_1[2], int i)
{
	if (close(pfd_0[1]) == -1)
		err_exit("close");
	if (i != 0 && close(pfd_1[0]) == -1)
		err_exit("close");
}

void	pipex_exec(char *argv[], int i)
{
	char	**child_argv;

	child_argv = ft_split(argv[2 + i], ' ');
	if (child_argv == NULL)
		err_exit("ft_split");
	if (ft_execvp(child_argv[0], child_argv) == -1)
		err_exit("ft_execvp");
}
