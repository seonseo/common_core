/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:56 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 17:03:13 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// static void chk()
// {
// 	system("leaks pipex");
// 	system("lsof -nc pipex");
// }

int	main(int argc, char *argv[])
{
	t_bool	here_doc;
	int	cmd_cnt;

	here_doc = check_here_doc(argv);
	pipex_argc_check(argc, here_doc);
	if (here_doc == FALSE)
	{
		cmd_cnt = argc - 3;
		execute_pipeline(argc, argv, cmd_cnt);
	}
	else
	{
		cmd_cnt = argc - 4;
		execute_pipeline_here_doc(argc, argv, cmd_cnt);
	}
	wait_children(argc, here_doc);
	exit(EXIT_SUCCESS);
}

t_bool	check_here_doc(char *argv[])
{
	if (ft_memcmp("here_doc", argv[1], 9) == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	pipex_argc_check(int argc, t_bool here_doc)
{
	if (here_doc == TRUE)
	{
		if (argc < 6)
			usage_err("here_doc LIMITER cmd1 cmd2 ... cmdn file");
	}
	else if (argc < 5)
		usage_err("infile cmd1 cmd2 ... cmdn outfile");
}

void	wait_children(int argc, t_bool here_doc)
{
	int	i;
	int	cmd_cnt;

	if (here_doc == FALSE)
		cmd_cnt = argc - 3;
	else
		cmd_cnt = argc - 4;
	i = 0;
	while (i < cmd_cnt)
	{
		if (wait(NULL) == -1)
			err_exit("wait");
		i++;
	}
}
