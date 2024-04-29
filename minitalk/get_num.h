/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:31:14 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/28 23:33:15 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NUM_H
#define GET_NUM_H

#define GN_NONNEG	01
#define GN_GT_0		02

#define GN_ANY_BASE	0100
#define GN_BASE_8	0200
#define GN_BASE_16	0400

long	getLong(const char *arg, int flags, const char *name);

int		getInt(const char *arg, int flags, const char *name);

#endif
