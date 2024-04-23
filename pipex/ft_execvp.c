/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:04:14 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/23 21:00:39 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char *const	environ[];

static void	ft_execvp_search(const char *file, char *const argv[], \
char **paths);
static char	*path_join(const char *dir, const char *file);
static void	free_strs(char **strs);

int	ft_execvp(const char *file, char *const argv[])
{
	char	**paths;

	if (file == NULL || *file == '\0')
	{
		errno = ENOENT;
		return (-1);
	}
	if (ft_strchr(file, '/'))
		return (execve(file, argv, environ));
	paths = ft_split(ft_getenv("PATH"), ':');
	if (paths == NULL)
		return (-1);
	ft_execvp_search(file, argv, paths);
	free_strs(paths);
	return (-1);
}

static void	ft_execvp_search(const char *file, char *const argv[], char **paths)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = path_join(paths[i], file);
		if (path == NULL)
			break ;
		if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) == 0 && execve(path, argv, environ) == -1)
			{
				free(path);
				break ;
			}
			else
			{
				free(path);
				break ;
			}
		}
		free(path);
		i++;
	}
}

static char	*path_join(const char *dir, const char *file)
{
	size_t	dir_len;
	size_t	file_len;
	size_t	full_path_len;
	char	*full_path;

	dir_len = ft_strlen(dir);
	file_len = ft_strlen(file);
	full_path_len = dir_len + file_len + 2;
	full_path = (char *)malloc(sizeof(char) * full_path_len);
	if (full_path == NULL)
		return (NULL);
	ft_strlcpy(full_path, dir, full_path_len);
	if (dir[dir_len - 1] != '/')
		ft_strlcat(full_path, "/", full_path_len);
	ft_strlcat(full_path, file, full_path_len);
	return (full_path);
}

static void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
