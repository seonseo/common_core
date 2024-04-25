/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_execute_pipeline_here_doc.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 14:49:01 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_pipeline_here_doc(int argc, char *argv[])
{
	int		pfd_0[2];
	int		pfd_1[2];
	int		pid;
	int		i;

	i = 0;
	while (i < argc - 4)
	{
		create_pipe_here_doc(argc, i, pfd_0, pfd_1);
		pid = safe_fork();
		if (pid == 0)
		{
			if (i == 0)
				pipex_child_left_here_doc(pfd_0, pfd_1);
			else if (i < (argc - 4) - 1)
				pipex_child_middle(pfd_0, pfd_1);
			else
				pipex_child_right(pfd_1, argv[argc - 1], TRUE);
			pipex_exec(argv, i, TRUE);
		}
		if (i == 0)
			here_doc(argv[2], pfd_1);
		close_pipes_here_doc(argc, pfd_0, pfd_1, i);
		pfd_1[0] = pfd_0[0];
		ft_dprintf(2, "pfd_1[0] = pfd_0[0]\n");
		i++;
	}
}

void	create_pipe_here_doc(int argc, int i, int pfd_0[2], int pfd_1[2])
{
	int	command_count;

	command_count = argc - 4;
	if (i < command_count - 1)
	{
		ft_dprintf(2, "create pfd_0 %d\n", i);
		if (pipe(pfd_0) == -1)
			err_exit("pipe");
	}
	if (i == 0)
	{
		ft_dprintf(2, "create pfd_1 %d\n", i);
		if (pipe(pfd_1) == -1)
			err_exit("pipe");
	}
}

void	close_pipes_here_doc(int argc, int pfd_0[2], int pfd_1[2], int i)
{
	int	command_count;

	command_count = argc - 4;
	if (i < command_count - 1)
	{
		ft_dprintf(2, "close pfd_0[1] %d\n", i);
		if (close(pfd_0[1]) == -1)
			err_exit("close_pipes 1");
	}
	if (i != 0)
	{
		ft_dprintf(2, "close pfd_1[0] %d\n", i);
		if (close(pfd_1[0]) == -1)
			err_exit("close_pipes 2");
	}
}
