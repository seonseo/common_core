/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:48:20 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/22 19:03:26 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern const char	**environ;

const char	*ft_getenv(const char *key)
{
	int		i;
	size_t	len;

	if (key == NULL)
		return (NULL);
	len = ft_strlen(key);
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], key, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}
