/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:17:16 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/18 14:01:23 by suminpar         ###   ########.fr       */
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
		if (pthread_create(&(philo[i].thread), NULL, ph_thread, &(philo[i])) != 0)
			return (1);
		i++;
		usleep(20);
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
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	if (philo->id % 2 == 0)
	{
		if (print_ph_state(philo, philo->id, "is thinking"))
			return (NULL);
		usleep(6000);
	}
	while (1)
	{
		if (philo->id % 2 == 0)
		{
			if (philo_eat_odd(philo, data))
				return (NULL);
		}
		else
		{
			if (philo_eat_even(philo, data))
				return (NULL);
		}
		if (print_ph_state(philo, philo->id, "is sleeping"))
			return (NULL);
		ft_usleep((long)data->time_to_sleep, data);
		if (print_ph_state(philo, philo->id, "is thinking"))
			return (NULL);
	}
	return (0);
}

// void	*ph_thread(void *argv)
// {
// 	t_philo	*philo;
// 	t_data	*data;

// 	philo = argv;
// 	data = philo->data;
// 	philo->last_eat_time = get_time();
// 	if (philo->id % 2 == 0)
// 		usleep(100);
// 	while (!(data->flag_finish))
// 	{
// 		philo_eat(philo, data);
// 		if (data->must_eat == philo->eat_cnt)
// 		{
// 			data->eat_all++;
// 			break ;
// 		}
// 		print_ph_state(philo, philo->id, "is sleeping");
// 		ft_usleep((long)data->time_to_sleep, data);
// 		print_ph_state(philo, philo->id, "is thinking");
// 	}
// 	return (0);
// }

int	philo_eat_odd(t_philo *philo, t_data *data)
{
	usleep(3000);
	pthread_mutex_lock(&(data->forks[philo->right]));
	if (print_ph_state(philo, philo->id, "has taken a fork"))
	{
		pthread_mutex_unlock(&(data->forks[philo->right]));
		return (1);
	}
	if (data->number_of_philo != 1)
	{
		pthread_mutex_lock(&(data->forks[philo->left]));
		if (print_ph_state(philo, philo->id, "has taken a fork") || 
		/*
			여기서 철학자가 식사하기 직전에 죽었는지 시간 체크.
		*/\
			print_ph_state(philo, philo->id, "is eating"))
		{
			pthread_mutex_unlock(&(data->forks[philo->left]));
			pthread_mutex_unlock(&(data->forks[philo->right]));
			return (1);
		}
		pthread_mutex_lock(&philo->eat_mutex);
		philo->last_eat_time = get_time();
		philo->eat_cnt++;
		pthread_mutex_unlock(&philo->eat_mutex);
		ft_usleep((long)data->time_to_eat, data);
		pthread_mutex_unlock(&(data->forks[philo->left]));
	}
	pthread_mutex_unlock(&(data->forks[philo->right]));
	return (0);
}

int	philo_eat_even(t_philo *philo, t_data *data)
{
	usleep(3000);
	pthread_mutex_lock(&(data->forks[philo->left]));
	if (print_ph_state(philo, philo->id, "has taken a fork"))
	{
		pthread_mutex_unlock(&(data->forks[philo->left]));
		return (1);
	}
	if (data->number_of_philo != 1)
	{
		pthread_mutex_lock(&(data->forks[philo->right]));
		if (print_ph_state(philo, philo->id, "has taken a fork") || 
		/*
			여기서 철학자가 식사하기 직전에 죽었는지 시간 체크.
		*/\
			print_ph_state(philo, philo->id, "is eating"))
		{
			pthread_mutex_unlock(&(data->forks[philo->left]));
			pthread_mutex_unlock(&(data->forks[philo->right]));
			return (1);
		}
		pthread_mutex_lock(&philo->eat_mutex);
		philo->last_eat_time = get_time();
		philo->eat_cnt++;
		pthread_mutex_unlock(&philo->eat_mutex);
		ft_usleep((long)data->time_to_eat, data);
		pthread_mutex_unlock(&(data->forks[philo->right]));
	}
	pthread_mutex_unlock(&(data->forks[philo->left]));
	return (0);
}

int	print_ph_state(t_philo *philo, int id, char *msg)
{
	pthread_mutex_lock(&(philo->data->print_mutex));
	pthread_mutex_lock(&philo->flag_finish_mutex);
	if (philo->flag_finish != 1)
		printf("%ld %d %s\n", get_time() - philo->data->start_time, id, msg);
	else
	{
		pthread_mutex_unlock(&philo->flag_finish_mutex);
		pthread_mutex_unlock(&(philo->data->print_mutex));
		return (1);	
	}
	pthread_mutex_unlock(&philo->flag_finish_mutex);
	pthread_mutex_unlock(&(philo->data->print_mutex));
	return (0);
}

void	check_finish(t_philo *philo, t_data *data)
{
	int		i;
	int		stop;

	while (1)
	{
		stop = 0;
		i = 0;
		while (i < data->number_of_philo)
		{
			pthread_mutex_lock(&philo[i].eat_mutex);
			if (data->must_eat > philo[i].eat_cnt)
				stop = 1;
			if (get_time() - philo[i].last_eat_time >= data->time_to_die)
			{
				print_ph_state(philo, i + 1, "died");
				i = -1;
				break ;
			}
			pthread_mutex_unlock(&philo[i].eat_mutex);
			i++;
		}
		if ((data->must_eat != 0 && stop == 0) || i == -1)
		{
			i = 0;
			while (i < data->number_of_philo)
			{
				pthread_mutex_lock(&philo[i].flag_finish_mutex);
				philo[i].flag_finish = 1;
				pthread_mutex_unlock(&philo[i].flag_finish_mutex);
				i++;
			}
			break ;
		}
		usleep(7000);
	}
}

// void	check_finish(t_philo *philo, t_data *data)
// {
// 	int		i;
// 	long	now;

// 	while (!(data->flag_finish))
// 	{
// 		if ((data->must_eat != 0) && (data->number_of_philo == data->eat_all))
// 		{
// 			data->flag_finish = 1;
// 			break ;
// 		}
// 		i = 0;
// 		while (i < data->number_of_philo)
// 		{
// 			now = get_time();
// 			if (now - philo[i].last_eat_time >= data->time_to_die)
// 			{
// 				print_ph_state(philo, i, "died");
// 				data->flag_finish = 1;
// 				break ;
// 			}
// 			i++;
// 		}
// 	}
// }
