/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:04:19 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/03 19:06:21 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_sighandler(int sig, siginfo_t *info, void *context)
{
	static pid_t	pid;
	static char		c;
	static int		c_idx;
	static char		buf[1024];
	static int		buf_idx;

	(void)context;
	if (pid && pid != info->si_pid)
	{
		c_idx = 0;
		write(STDOUT_FILENO, buf, buf_idx);
		buf_idx = 0;
	}
	if (pid == 0)
		pid = info->si_pid;

	if (sig == SIGUSR1)
		c = c | (1 << c_idx);
	else if (sig == SIGUSR2)
		c = c & (~(1 << c_idx));

	c_idx++;
	if (c_idx == 8)
	{
		c_idx = 0;
		buf[buf_idx] = c;
		buf_idx++;
		if (c == '\0' || buf_idx == 1024)
		{
			write(STDOUT_FILENO, buf, buf_idx);
			buf_idx = 0;
		}
	}
	kill(pid, SIGUSR1);
	if (c == '\0')
		pid = 0;
}

int	main(void)
{
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = server_sighandler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		fatal("sigaction 1");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		fatal("isgaction 2");
	if (ft_printf("%d\n", (int)getpid()) == -1)
		fatal("ft_printf");
	while (1)
		pause();
	return (0);
}
