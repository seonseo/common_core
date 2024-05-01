/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:05:43 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/01 19:53:09 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	gn_fail(const char *fname, const char *msg, \
const char *arg, const char *name)
{
	ft_dprintf(STDERR_FILENO, "%s error", fname);
	if (name != NULL)
		ft_dprintf(STDERR_FILENO, " (in %s)", name);
	ft_dprintf(STDERR_FILENO, ": %s\n", msg);
	if (arg != NULL && *arg != '\0')
		ft_dprintf(STDERR_FILENO, "		offending text: %s\n", arg);
	exit(EXIT_FAILURE);
}

static long	get_num(const char *fname, const char *arg, \
int flags, const char *name)
{
	long	res;
	char	*endptr;
	int		base;

	if (arg == NULL || *arg == '\0')
		gn_fail(fname, "null or empty string", arg, name);
	if (flags & GN_ANY_BASE)
		base = 0;
	else if (flags & GN_BASE_8)
		base = 8;
	else if (flags & GN_BASE_16)
		base = 16;
	else
		base = 10;
	res = ft_strtol(arg, &endptr, base);
	if (*endptr != '\0')
		gn_fail(fname, "nonnumeric characters", arg, name);
	if ((flags & GN_NONNEG) && res < 0)
		gn_fail(fname, "negative value not allowed", arg, name);
	if ((flags & GN_GT_0) && res <= 0)
		gn_fail(fname, "value must be > 0", arg, name);
	return (res);
}

long	get_long(const char *arg, int flags, const char *name)
{
	return (get_num("get_long", arg, flags, name));
}

int	get_int(const char *arg, int flags, const char *name)
{
	long	res;

	res = get_num("get_int", arg, flags, name);
	if (res > INT_MAX || res < -INT_MAX - 1)
		gn_fail("get_int", "integer out of range", arg, name);
	return ((int)res);
}
