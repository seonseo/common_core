/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:56:10 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/22 13:41:38 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*g_ename[] = {
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
#define BUF_SIZE 500

void	output_error(t_bool use_err, int err, const char *format, va_list args)
{
	char	buf[BUF_SIZE];
	char	user_msg[BUF_SIZE];
	char	err_text[BUF_SIZE];
	char	*error_name;

	ft_vsnprintf(user_msg, BUF_SIZE, format, args);
	if (use_err)
	{
		if (0 < err && err <= MAX_ENAME)
			error_name = g_ename[err];
		else
			error_name = "?UNKNOWN?";
		ft_snprintf(err_text, BUF_SIZE, " [%s %s]", error_name, strerror(err));
	}
	else
		ft_snprintf(err_text, BUF_SIZE, ":");
	ft_snprintf(buf, BUF_SIZE, "ERROR%s %s\n", err_text, user_msg);
	ft_putstr_fd(buf, 2);
}
