/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:53:56 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/21 00:20:05 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(t_philo *philo, t_data *data, char *str)
{
	free_data_philo(philo, data);
	printf("Error: %s\n", str);
	return (1);
}

int	ph_move_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ph_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;
	long	tmp;

	sign = 1;
	result = 0;
	i = ph_move_sign(str, &sign);
	if (!str[i--])
		return (-1);
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		tmp = result;
		result = (result * 10) + (str[i] - '0');
		if (tmp > result)
			return (-1);
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
		return (-1);
	return (result);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, long start, long sleep_time)
{
	long	now;

	now = get_time() - start;
	while (now < sleep_time)
	{
		if (now + 10 < sleep_time)
			usleep(1500);
		else
			usleep(100);
		pthread_mutex_lock(&philo->flag_finish_mutex);
		if (philo->flag_finish)
		{
			pthread_mutex_unlock(&philo->flag_finish_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->flag_finish_mutex);
		now = get_time() - start;
	}
}
