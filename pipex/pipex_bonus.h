/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:10:09 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/23 23:10:53 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <sys/wait.h>

//pipex_bonus.c
void		check_here_doc(char *argv[], t_bool *here_doc);
void		pipex_argc_check(int argc, t_bool here_doc);
void		wait_children(int argc, t_bool here_doc);

//pipex_bonus_execute_pipeline.c
void		execute_pipeline(int argc, char *argv[], t_bool here_doc);
void		create_pipe(int argc, int i, int pfd[2]);
void		safe_fork(int *pid);
void		pipex_exec(char *argv[], int i);
void		close_pipes(int pfd_0[2], int pfd_1[2], int i);

//pipex_bonus_child.c
void		pipex_child_left(int pfd_0[2], char *infile);
void		pipex_child_middle(int pfd_0[2], int pfd_1[2]);
void		pipex_child_right(int pfd_1[2], char *outfile, t_bool heredoc);

//ft_execvp.c
int			ft_execvp(const char *file, char *const argv[]);

//ft_getenv.c
const char	*ft_getenv(const char *key);

#endif
