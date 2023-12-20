/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:53:42 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/21 01:16:53 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_behavior(t_philo *philo, t_data *data)
{
	long	time;

	while (1)
	{
		if (philo_eat(philo, data))
			return ;
		time = print_ph_state(philo, philo->id, "is sleeping", 1);
		if (!time)
			return ;
		ft_usleep(philo, time, (long)data->time_to_sleep);
		if (!print_ph_state(philo, philo->id, "is thinking", 0))
			return ;
		usleep(500);
	}
}

long	print_ph_state(t_philo *philo, int id, char *msg, int needtime)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_time();
	if (philo->flag_finish)
	{
		pthread_mutex_unlock(&(philo->data->print_mutex));
		return (0);
	}
	else
		printf("%ld %d %s\n", time - philo->data->start_time, id, msg);
	pthread_mutex_unlock(&(philo->data->print_mutex));
	if (needtime)
		return (time);
	return (1);
}

int	philo_eat_set(t_philo *philo, t_data *data)
{
	long	time;

	pthread_mutex_lock(&philo->eat_mutex);
	philo_dead(philo, data);
	time = print_ph_state(philo, philo->id, "is eating", 1);
	if (!time)
	{
		pthread_mutex_unlock(&philo->eat_mutex);
		return (1);
	}
	philo->last_eat_time = time;
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(philo, time, (long)data->time_to_eat);
	return (0);
}

void	philo_dead(t_philo *philo, t_data *data)
{
	if (get_time() - philo->last_eat_time > data->time_to_die)
	{
		pthread_mutex_lock(&philo->flag_finish_mutex);
		philo->flag_finish = 1;
		pthread_mutex_unlock(&philo->flag_finish_mutex);
	}
}

void	ph_fork_down(t_philo *philo, t_data *data)
{
	pthread_mutex_unlock(&(data->forks[philo->left]));
	pthread_mutex_unlock(&(data->forks[philo->right]));
}
