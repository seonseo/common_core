/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:52:03 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/24 23:05:17 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int is_fd_available(int fd);


void	pipex_child_left(int pfd_0[2], char *infile)
{
	int	infile_fd;

	if (close(pfd_0[0]) == -1)
		err_exit("close left 1");
	if (dup2(pfd_0[1], STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_0[1]) == -1)
		err_exit("close left 2");
	infile_fd = open(infile, O_RDONLY, (mode_t)0777);
	if (infile_fd == -1)
		err_exit("open");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(infile_fd) == -1)
		err_exit("close left 3");
}

void	pipex_child_left_here_doc(int pfd_0[2], int pfd_1[2])
{
	if (close(pfd_0[0]) == -1)
		err_exit("close here_doc left 1");
	ft_dprintf(2, "close pfd_0[0] left\n");
	if (dup2(pfd_0[1], STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_0[1]) == -1)
		err_exit("close here_doc left 2");
	ft_dprintf(2, "close pfd_0[1] left\n");

	if (close(pfd_1[1]) == -1)
		err_exit("close here_doc left 3");
	ft_dprintf(2, "close pfd_1[1] left\n");
	if (dup2(pfd_1[0], STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_1[0]) == -1)
		err_exit("close here_doc left 4");
	ft_dprintf(2, "close pfd_1[0] left\n");
}

void	pipex_child_middle(int pfd_0[2], int pfd_1[2])
{
	ft_dprintf(2, "middle\n");
	if (close(pfd_0[0]) == -1)
		err_exit("close middle 1");
	if (dup2(pfd_0[1], STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_0[1]) == -1)
		err_exit("close middle 2");

	if (dup2(pfd_1[0], STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_1[0]) == -1)
		err_exit("close middle 3");
}

void	pipex_child_right(int pfd_1[2], char *outfile, t_bool here_doc)
{
	int	outfile_fd;

	if (dup2(pfd_1[0], STDIN_FILENO) == -1)
		err_exit("dup2");
	if (close(pfd_1[0]) == -1)
		err_exit("close right 1");
	ft_dprintf(2, "close pfd_1[0] right\n");
	if (here_doc == TRUE)
		outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND, (mode_t)0777);
	else
		outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, (mode_t)0777);
	if (outfile_fd == -1)
		err_exit("open");
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		err_exit("dup2");
	if (close(outfile_fd) == -1)
		err_exit("close right 2");
}

int is_fd_available(int fd)
{
    return fcntl(fd, F_GETFD) != -1 || errno != EBADF;
}
