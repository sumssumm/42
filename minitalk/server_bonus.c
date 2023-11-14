/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:08:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/14 21:03:47 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo)
{
	static int	bit;
	static int	bit_cnt;

	if (signo == SIGUSR1)
		bit |= (1 << bit_cnt);
	bit_cnt++;
	if (bit_cnt == 8)
	{
		ft_printf("%c", (unsigned char)bit);
		bit = 0;
		bit_cnt = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try only ./server\n");
		return (0);
	}
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	sa.sa_handler = &signal_handler;
	sa.sa_flags = 0;
	// saemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
