/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:08:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/25 03:49:20 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler2(int signo, siginfo_t *info, void *context)
{
	static int	bit;
	static int	bit_cnt;

	(void)context;
	if (signo == SIGUSR1)
		bit |= (1 << bit_cnt);
	bit_cnt++;
	if (bit_cnt == 8)
	{
		write(1, &bit, 1);
		if (bit == '\0')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		bit_cnt = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try only ./server\n");
		return (0);
	}
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler2;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
