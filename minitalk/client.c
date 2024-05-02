/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:03:58 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/02 23:24:31 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_sighandler(int sig)
{
	return ;
}

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR1) == -1)
				fatal("kill");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				fatal("kill");
		}
		pause();
		i++;
	}
}

static void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	act;

	if (argc != 3)
		usage_err("pid string");
	pid = get_int(argv[1], GN_GT_0, "pid");
	act.sa_flags = 0;
	act.sa_handler = client_sighandler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		fatal("sigaction 1");
	send_str(pid, argv[2]);
	exit(EXIT_SUCCESS);
}
