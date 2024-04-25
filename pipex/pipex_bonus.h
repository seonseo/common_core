/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:10:09 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 22:59:08 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <sys/wait.h>

//pipex_bonus.c
t_bool		check_here_doc(char *argv[]);
void		pipex_argc_check(int argc, t_bool here_doc);
void		wait_children(int cmd_cnt);

//pipex_bonus_here_doc.c
void		here_doc(char *limiter, int i, int pfd[2]);
char		*here_doc_get_string(char *limiter);

//pipex_bonus_execute_pipeline.c
void		execute_pipeline(int argc, char *argv[], char *envp[], int cmd_cnt);
void		create_pipe(int cmd_cnt, int i, int pfd[2]);
int			safe_fork(void);
void		pipex_exec(char *argv[], char *envp[], int i, t_bool here_doc);
void		close_pipes(int cmd_cnt, int i, int pfd_0[2], int pfd_1[2]);

//pipex_bonus_execute_pipeline_here_doc.c
void		execute_pipeline_here_doc(int argc, char *argv[], char *envp[], \
int cmd_cnt);
void		create_pipe_here_doc(int cmd_cnt, int i, \
int pfd_0[2], int pfd_1[2]);
void		close_pipes_here_doc(int cmd_cnt, int i, \
int pfd_0[2], int pfd_1[2]);

//pipex_bonus_child.c
void		pipex_child_left(int pfd_0[2], char *infile);
void		pipex_child_left_here_doc(int pfd_0[2], int pfd_1[2]);
void		pipex_child_middle(int pfd_0[2], int pfd_1[2]);
void		pipex_child_right(int pfd_1[2], char *outfile, t_bool heredoc);

//ft_execvp.c
int			ft_execvpe(const char *file, char *const argv[], char *envp[]);

//ft_getenv.c
const char	*ft_getenv(const char *key, char *envp[]);

#endif
