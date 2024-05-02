/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:04:19 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/02 23:10:29 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_sighandler(int sig, siginfo_t *info, void *context)
{
	static char		c;
	static int		i;
	static pid_t	pid;

	context = NULL;
	if (pid && pid != info->si_pid)
		i = 0;
	pid = info->si_pid;
	if (sig == SIGUSR1)
		c = c | (1 << i);
	else if (sig == SIGUSR2)
		c = c & (~(1 << i));
	i++;
	if (i == 8)
	{
		i = 0;
		if (write(STDOUT_FILENO, &c, 1) == -1)
			fatal("write");
	}
	kill(info->si_pid, SIGUSR1);
	return ;
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
	return (1);
}
