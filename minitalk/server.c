/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:04:19 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/29 09:32:19 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	add_bit(char *str, int i, int bit)
{
	
}

static void	sighandler(int sig)
{
	static int	i;
	static char	str[1024];

	if (sig == SIGUSR1)
		add_bit(str, i, 0);
	else
		add_bit(str, i, 1);
	i++;
	return ;
}

int	main(void)
{
	struct sigaction act;

	act = (struct sigaction){};
	act.sa_handler = sighandler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("pid: %d\n", (int)getpid());
	while (1)
		pause();
	return (1);
}
