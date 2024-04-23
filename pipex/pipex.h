/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:10:09 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/23 21:03:41 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

void		pipex_fork(char *argv[], int pfd[2]);
void		pipex_child_left(int pfd[2], char *infile);
void		pipex_child_right(int pfd[2], char *outfile);
void		pipex_exec(char *argv[], int i);

int			ft_execvp(const char *file, char *const argv[]);
const char	*ft_getenv(const char *key);

#endif
