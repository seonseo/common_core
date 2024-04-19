/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:53 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/19 15:25:46 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_FUNCTIONS_H
# define ERROR_FUNCTIONS_H

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char *ename[] = {
    "", "EPERM", "ENOENT", "ESRCH", "EINTR", "EIO", "ENXIO", "E2BIG",
    "ENOEXEC", "EBADF", "ECHILD", "EDEADLK", "ENOMEM", "EACCES", "EFAULT",
    "ENOTBLK", "EBUSY", "EEXIST", "EXDEV", "ENODEV", "ENOTDIR", "EISDIR",
    "EINVAL", "ENFILE", "EMFILE", "ENOTTY", "ETXTBSY", "EFBIG", "ENOSPC",
    "ESPIPE", "EROFS", "EMLINK", "EPIPE", "EDOM", "ERANGE", "EAGAIN",
    "EINPROGRESS", "EALREADY", "ENOTSOCK", "EDESTADDRREQ", "EMSGSIZE",
    "EPROTOTYPE", "ENOPROTOOPT", "EPROTONOSUPPORT", "ESOCKTNOSUPPORT",
    "ENOTSUP", "EPFNOSUPPORT", "EAFNOSUPPORT", "EADDRINUSE",
    "EADDRNOTAVAIL", "ENETDOWN", "ENETUNREACH", "ENETRESET",
    "ECONNABORTED", "ECONNRESET", "ENOBUFS", "EISCONN", "ENOTCONN",
    "ESHUTDOWN", "ETOOMANYREFS", "ETIMEDOUT", "ECONNREFUSED", "ELOOP",
    "ENAMETOOLONG", "EHOSTDOWN", "EHOSTUNREACH", "ENOTEMPTY", "EPROCLIM",
    "EUSERS", "EDQUOT", "ESTALE", "EREMOTE", "EBADRPC", "ERPCMISMATCH",
    "EPROGUNAVAIL", "EPROGMISMATCH", "EPROCUNAVAIL", "ENOLCK", "ENOSYS",
    "EFTYPE", "EAUTH", "ENEEDAUTH", "EPWROFF", "EDEVERR", "EOVERFLOW",
    "EBADEXEC", "EBADARCH", "ESHLIBVERS", "EBADMACHO", "ECANCELED", "EIDRM",
    "ENOMSG", "EILSEQ", "ENOATTR", "EBADMSG", "EMULTIHOP", "ENODATA",
    "ENOLINK", "ENOSR", "ENOSTR", "EPROTO", "ETIME", "EOPNOTSUPP", "ENOPOLICY",
    "ENOTRECOVERABLE", "EOWNERDEAD", "EQFULL"
};

#define MAX_ENAME 106

void	output_error(t_bool use_err, int err, const char *format, va_list args);
void	err_msg(const char *format, ...);
void	err_exit(const char *format, ...);
void	fatal(const char *format, ...);
void	usage_err(const char *format, ...);
void	cmd_line_error(const char *format, ...);

#endif
