/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:08:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/25 04:05:01 by suminpar         ###   ########.fr       */
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
		write(1, &bit, 1);
		bit = 0;
		bit_cnt = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try only ./server\n");
		return (0);
	}
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
