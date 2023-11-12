/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:08:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/12 23:02:18 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo)
{
	static int	bit;
	static int	bit_cnt;

	// ft_printf("signo : %d\n", signo);
	if (signo == SIGUSR1)
		bit |= (1 << bit_cnt);
	// ft_printf("%d\n", bit);
	bit_cnt++;
	if (bit_cnt == 8)
	{
		ft_printf("%c", (char)bit);
		bit = 0;
		bit_cnt = 0;
	}
}

int main(int argc, char **argv)
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
	sa.sa_flags = 0;
	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}