/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_execute_pipeline_here_doc.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:49 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 17:02:56 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_pipeline_here_doc(int argc, char *argv[], int cmd_cnt)
{
	int			pfd_0[2];
	int			pfd_1[2];
	int			pid;
	int		i;

	i = 0;
	while (i < argc - 4)
	{
		create_pipe_here_doc(cmd_cnt, i, pfd_0, pfd_1);
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
		here_doc(argv[2], i, pfd_1);
		close_pipes_here_doc(cmd_cnt, i, pfd_0, pfd_1);
		pfd_1[0] = pfd_0[0];
		i++;
	}
}

void	create_pipe_here_doc(int cmd_cnt, int i, int pfd_0[2], int pfd_1[2])
{
	if (i < cmd_cnt - 1)
	{
		if (pipe(pfd_0) == -1)
			err_exit("pipe");
	}
	if (i == 0)
	{
		if (pipe(pfd_1) == -1)
			err_exit("pipe");
	}
}

void	close_pipes_here_doc(int cmd_cnt, int i, int pfd_0[2], int pfd_1[2])
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
