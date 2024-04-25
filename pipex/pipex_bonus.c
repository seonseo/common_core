/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:56 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 15:02:26 by seonseo          ###   ########.fr       */
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
	t_bool here_doc;

	// atexit(chk);
	here_doc = check_here_doc(argv);
	pipex_argc_check(argc, here_doc);
	if (here_doc == FALSE)
		execute_pipeline(argc, argv);
	else
		execute_pipeline_here_doc(argc, argv);
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
	int	command_count;

	ft_dprintf(2, "wait\n");
	if (here_doc == FALSE)
		command_count = argc - 3;
	else
		command_count = argc - 4;
	i = 0;
	while (i < command_count)
	{
		if (wait(NULL) == -1)
			err_exit("wait");
		i++;
	}
}

void	here_doc(char *limiter, int pfd_1[2])
{
	char	*save;
	size_t	save_len;

	if (close(pfd_1[0]) == -1)
		err_exit("close here_doc read");
	ft_dprintf(2, "close pfd_1[0] heredoc\n");
	save = here_doc_get_string(limiter);
	save_len = ft_strlen(save);
	if (write(pfd_1[1], save, save_len) != (ssize_t)save_len)
		err_exit("write");
	free(save);
	if (close(pfd_1[1] == -1))
		err_exit("close here_doc write");
	ft_dprintf(2, "close pfd_1[1] heredoc\n");
}

char	*here_doc_get_string(char *limiter)
{
	char	*line;
	char	*buf;
	char	*save;

	save = NULL;
	while(1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			fatal("get_next_line failed");
		if (ft_memcmp(line, limiter, ft_strlen(limiter)) == 0 && \
		ft_memcmp(&line[ft_strlen(limiter)], "\n", 1) == 0)
			break;
		buf = ft_strjoin(save, line);
		if (buf == NULL)
			fatal("ft_strjoin failed");
		free(save);
		free(line);
		save = buf;
	}
	return (save);
}
