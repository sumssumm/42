/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:17:16 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/20 18:57:10 by suminpar         ###   ########.fr       */
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
		if (pthread_create(&(philo[i].thread), NULL, ph_thread, &(philo[i])))
			return (1);
		i++;
	}
	check_alive(philo, data);
	i = 0;
	while (i < data->number_of_philo)
		pthread_join(philo[i++].thread, NULL);
	return (0);
}

void	*ph_thread(void *argv)
{
	t_philo	*philo;
	t_data	*data;

	philo = argv;
	data = philo->data;
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	if (philo->id % 2 == 0 || philo->id == data->number_of_philo)
	{
		if (!print_ph_state(philo, philo->id, "is thinking", 0))
			return (NULL);
		usleep(data->time_to_eat * 900);
	}
	ph_behavior(philo, data);
	return (NULL);
}

void	check_alive(t_philo *philo, t_data *data)
{
	int		stop;
	int		pos;

	while (1)
	{
		pos = -1;
		stop = ph_dead_or_must_set(philo, data, &pos);
		if ((data->must_eat != 0 && stop == 0) || pos != -1)
		{
			ph_stop_or_dead(philo, data, pos);
			break ;
		}
		usleep(5000);
	}
}

int	ph_dead_or_must_set(t_philo *philo, t_data *data, int *pos)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_lock(&philo[i].eat_mutex);
		if (data->must_eat > philo[i].eat_cnt)
			stop = 1;
		if (philo[i].last_eat_time != 0 && \
			get_time() - philo[i].last_eat_time > data->time_to_die)
		{
			*pos = i;
			pthread_mutex_unlock(&philo[i].eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo[i].eat_mutex);
		i++;
	}
	return (stop);
}

void	ph_stop_or_dead(t_philo *philo, t_data *data, int pos)
{
	int	i;

	pthread_mutex_lock(&data->print_mutex);
	if (pos != -1)
		printf("%ld %d died\n", \
				get_time() - philo[pos].data->start_time, pos + 1);
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_lock(&philo[i].flag_finish_mutex);
		philo[i].flag_finish = 1;
		pthread_mutex_unlock(&philo[i].flag_finish_mutex);
		i++;
	}
	pthread_mutex_unlock(&data->print_mutex);
}
