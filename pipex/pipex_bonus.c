/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:56 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/23 23:08:07 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[])
{
	t_bool here_doc;

	check_here_doc(argv, &here_doc);
	pipex_argc_check(argc, here_doc);
	execute_pipeline(argc, argv, here_doc);
	wait_children(argc, here_doc);
	exit(EXIT_SUCCESS);
}

void	check_here_doc(char *argv[], t_bool *here_doc)
{
	if (ft_memcmp("here_doc", argv[1], 9) == 0)
		*here_doc = TRUE;
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
	int	command_count;

	if (here_doc == TRUE)
		command_count = argc - 4;
	else
		command_count = argc - 3;
	i = 0;
	while (i < command_count)
	{
		if (wait(NULL) == -1)
			err_exit("wait");
		i++;
	}
}
