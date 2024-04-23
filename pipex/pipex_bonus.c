/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:56 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/23 20:57:21 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[])
{
	if (argc < 5)
		usage_err("infile cmd1 cmd2 ... cmdn outfile");
	execute_pipeline(argc, argv);
	wait_child(argc);
	exit(EXIT_SUCCESS);
}

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
		safe_fork(&pid);
		if (pid == 0)
		{
			if (i == 0)
				pipex_child_left(pfd_0, argv[1]);
			else if (i < argc - 4)
				pipex_child_middle(pfd_0, pfd_1);
			else
				pipex_child_right(pfd_1, argv[argc - 1]);
			pipex_exec(argv, i);
		}
		close_pipes(pfd_0, pfd_1, i);
		pfd_1[0] = pfd_0[0];
		i++;
	}
	close(pfd_0[0]);
}

void	wait_children(int argc)
{
	int	i;

	i = 0;
	while (i < argc - 4)
	{
		if (wait(NULL) == -1)
			err_exit("wait");
		i++;
	}
}
