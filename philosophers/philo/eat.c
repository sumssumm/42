/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:53:39 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/20 22:46:22 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo, t_data *data)
{
	if (philo->id & 1)
	{
		if (philo_eat_odd(philo, data))
			return (1);
	}
	else
	{
		if (philo_eat_even(philo, data))
			return (1);
	}
	return (0);
}

int	philo_eat_even(t_philo *philo, t_data *data)
{
	if (ph_right_fork_up(philo, data))
		return (1);
	if (ph_left_fork_up(philo, data))
	{
		pthread_mutex_unlock(&(data->forks[philo->right]));
		return (1);
	}
	if (philo_eat_set(philo, data))
	{
		ph_fork_down(philo, data);
		return (1);
	}
	pthread_mutex_unlock(&(data->forks[philo->right]));
	pthread_mutex_unlock(&(data->forks[philo->left]));
	return (0);
}

int	philo_eat_odd(t_philo *philo, t_data *data)
{
	if (ph_left_fork_up(philo, data))
		return (1);
	if (data->number_of_philo == 1)
	{
		pthread_mutex_unlock(&(data->forks[philo->left]));
		return (0);
	}
	if (ph_right_fork_up(philo, data))
	{
		pthread_mutex_unlock(&(data->forks[philo->left]));
		return (1);
	}
	if (philo_eat_set(philo, data))
	{
		ph_fork_down(philo, data);
		return (1);
	}
	pthread_mutex_unlock(&(data->forks[philo->left]));
	pthread_mutex_unlock(&(data->forks[philo->right]));
	return (0);
}

int	ph_left_fork_up(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->forks[philo->left]));
	if (!print_ph_state(philo, philo->id, "has taken a fork", 0))
	{
		pthread_mutex_unlock(&(data->forks[philo->left]));
		return (1);
	}
	return (0);
}

int	ph_right_fork_up(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->forks[philo->right]));
	if (!print_ph_state(philo, philo->id, "has taken a fork", 0))
	{
		pthread_mutex_unlock(&(data->forks[philo->right]));
		return (1);
	}
	return (0);
}
