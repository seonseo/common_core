/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:05:43 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/29 11:36:08 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "libft.h"
#include "get_num.h"

static void	gnFail(const char *fname, const char *msg, const char *arg, const char *name)
{
	ft_dprintf(STDERR_FILENO, "%s error", fname);
	if (name != NULL)
		ft_dprintf(STDERR_FILENO, " (in %s)", name);
	ft_dprintf(STDERR_FILENO, ": %s\n", msg);
	if (arg != NULL && *arg != '\0')
		ft_dprintf(STDERR_FILENO, "		offending text: %s\n", arg);
    exit(EXIT_FAILURE);
}

static long	getNum(const char *fname, const char *arg, int flags, const char *name)
{
	long	res;
	char	*endptr;
	int		base;

	if (arg == NULL || *arg == '\0')
		gnFail(fname, "null or empty string", arg, name);
	
	base = (flags & GN_ANY_BASE) ? 0 : (flags & GN_BASE_8) ? 8 : (flags & GN_BASE_16) ? 16 : 10;
	
	errno = 0;
	res  = strtol(arg, &endptr, base);
	if (errno != 0)
		gnFail(fname, "strtol() failed", arg, name);

	if (*endptr != '\0')
		gnFail(fname, "nonnumeric characters", arg, name);
	
	if ((flags & GN_NONNEG) && res < 0)
		gnFail(fname, "negative value not allowed", arg, name);
	
	if ((flags & GN_GT_0) && res <= 0)
		gnFail(fname, "value must be > 0", arg, name);

	return res;
}

long	getLong(const char *arg, int flags, const char *name)
{
	return (getNum("getLong", arg, flags, name));
}

int getInt(const char *arg, int flags, const char *name)
{
	long res;

	res = getNum("getInt", arg, flags, name);
	if (res > INT_MAX || res < INT_MIN)
		gnFail("getInt", "integer out of range", arg, name);

	return ((int)res);
}

