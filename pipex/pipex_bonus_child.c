/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:52:03 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/23 20:52:31 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_child_left(int pfd_0[2], char *infile)
{
	int	infile_fd;

	if (close(pfd_0[0]) == -1)
		err_exit("close 2");
	if (dup2(pfd_0[1], STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_0[1]) == -1)
		err_exit("close 3");
	infile_fd = open(infile, O_RDONLY, (mode_t)0777);
	if (infile_fd == -1)
		err_exit("open 1");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(infile_fd) == -1)
		err_exit("close 4");
}

void	pipex_child_middle(int pfd_0[2], int pfd_1[2])
{
	if (close(pfd_0[0]) == -1)
		err_exit("close");
	if (dup2(pfd_1[0], STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_1[0]) == -1)
		err_exit("close 6");
	if (dup2(pfd_0[1], STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_0[1]) == -1)
		err_exit("close 3");
}

void	pipex_child_right(int pfd_1[2], char *outfile)
{
	int	outfile_fd;

	if (dup2(pfd_1[0], STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_1[0]) == -1)
		err_exit("close 6");
	outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, (mode_t)0777);
	if (outfile_fd == -1)
		err_exit("open 2");
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(outfile_fd) == -1)
		err_exit("close 7");
}
