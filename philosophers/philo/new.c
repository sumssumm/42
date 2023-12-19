#include "philo.h"

int	philo_eat(t_philo *philo, t_data *data)
{
	if (philo->id % 2 == 0)
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
		ft_usleep(time, (long)data->time_to_sleep);
		if (!print_ph_state(philo, philo->id, "is thinking", 0))
			return ;
		if (data->number_of_philo % 2 == 1)
			usleep(2000);
		else
			usleep(500);
	}
}

int	philo_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&philo->eat_mutex);
	if (get_time() - philo->last_eat_time > data->time_to_die)
	{
		pthread_mutex_lock(&philo->flag_finish_mutex);
		philo->flag_finish = 1;
		pthread_mutex_unlock(&philo->flag_finish_mutex);
	}
	pthread_mutex_unlock(&philo->eat_mutex);
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

void	ph_fork_down(t_philo *philo, t_data *data)
{
	pthread_mutex_unlock(&(data->forks[philo->left]));
	pthread_mutex_unlock(&(data->forks[philo->right]));
}

int	philo_eat_set(t_philo *philo, t_data *data)
{
	long	time;

	pthread_mutex_lock(&philo->eat_mutex);
	time = print_ph_state(philo, philo->id, "is eating", 1);
	if (!time)
	{
		pthread_mutex_unlock(&philo->eat_mutex);
		return (1);
	}
	philo->last_eat_time = time;
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(time, (long)data->time_to_eat);
	return (0);
}
