/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_here_doc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:56 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/25 17:17:43 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *limiter, int i, int pfd_1[2])
{
	char	*save;
	size_t	save_len;

	if (i != 0)
		return ;
	if (close(pfd_1[0]) == -1)
		err_exit("close here_doc read");
	save = here_doc_get_string(limiter);
	if (save == NULL)
		save = ft_strdup("");
	save_len = ft_strlen(save);
	if (write(pfd_1[1], save, save_len) != (ssize_t)save_len)
		err_exit("write");
	free(save);
	if (close(pfd_1[1]) == -1)
		err_exit("close here_doc write");
}

char	*here_doc_get_string(char *limiter)
{
	char	*line;
	char	*buf;
	char	*save;
	size_t	limiter_len;

	save = NULL;
	limiter_len = ft_strlen(limiter);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			fatal("get_next_line failed");
		if (ft_memcmp(line, limiter, limiter_len) == 0 && \
		ft_memcmp(&line[limiter_len], "\n", 1) == 0)
			break ;
		buf = ft_strjoin(save, line);
		if (buf == NULL)
			fatal("ft_strjoin failed");
		free(save);
		free(line);
		save = buf;
	}
	free(line);
	return (save);
}
