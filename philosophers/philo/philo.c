/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:17:16 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/12 13:41:57 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->number_of_philo)
	{
		philo[i].last_eat_time = get_time();
		if (philo[i].last_eat_time == -1)
			return (1);
		if (pthread_create(&(philo[i].thread), NULL, ph_thread, &(philo[i])) != 0)
			return (1);
		i++;
	}
	check_finish(philo, data);
	i = 0;
	while (i < data->number_of_philo)
		pthread_join(philo[i++].thread, NULL);
	// finish_thread(philo, data);
	return (0);
}

void	*ph_thread(void *argv)
{
	t_philo	*philo;
	t_data	*data;

	philo = argv;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!(data->flag_finish))
	{
		philo_eat(philo, data);
		if (data->time_to_eat == philo->eat_cnt)
		{
			data->finish_eat++;
			break ;
		}
		print_ph_state(data, philo->id, "is sleeping");
		ft_usleep((long)data->time_to_sleep, data);
		print_ph_state(data, philo->id, "is thinking");
	}
	return (0);
}

int	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	print_ph_state(data, philo->id, "has taken a fork");
	if (data->number_of_philo != 1)
	{
		pthread_mutex_lock(&(data->forks[philo->right_fork]));
		print_ph_state(data, philo->id, "has taken a fork");
		print_ph_state(data, philo->id, "is eating");
		philo->last_eat_time = get_time();
		if (philo->last_eat_time == -1)
			return (1);
		philo->eat_cnt++;
		ft_usleep((long)data->time_to_eat, data);
		pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	}
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
	return (0);
}

int	print_ph_state(t_data *data, int id, char *msg)
{
	long	now;

	now = get_time();
	if (now == -1)
		return (1);
	pthread_mutex_lock(&(data->print_mutex));
	if (!(data->flag_finish))
		printf("%ld %d %s\n", now - data->start_time, id, msg);
	pthread_mutex_unlock(&(data->print_mutex));
	return (0);
}

void	check_finish(t_philo *philo, t_data *data)
{
	int		i;
	long	now;

	while (!(data->flag_finish))
	{
		if ((data->time_to_eat != 0) && (data->number_of_philo == data->finish_eat))
		{
			data->flag_finish = 1;
			break ;
		}
		i = 0;
		while (i < data->number_of_philo)
		{
			now = get_time();
			if (now - philo[i].last_eat_time >= data->time_to_die)
			{
				print_ph_state(data, i, "died");
				data->flag_finish = 1;
				break ;
			}
			i++;
		}
	}
}
