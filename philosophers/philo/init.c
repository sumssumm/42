#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philo = ph_atoi(argv[1]);
	data->time_to_die = ph_atoi(argv[2]);
	data->time_to_eat = ph_atoi(argv[3]);
	data->time_to_sleep = ph_atoi(argv[4]);
	data->must_eat = 0;
	data->start_time = 0;
	if (data->number_of_philo < 1 || data->time_to_die < 0 \
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		data->must_eat = ph_atoi(argv[5]);
		if (data->must_eat <= 0)
			return (1);
	}
	if (init_data_mutex(data) == 1)
		return (1);
	return (0);
}

int	init_data_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (data->forks == NULL)
		return (1);
	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->number_of_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = (i + 1) % data->number_of_philo;
		philo[i].eat_cnt = 0;
		philo[i].last_eat_time = 0;
		philo[i].flag_finish = 0;
		pthread_mutex_init(&philo[i].flag_finish_mutex, NULL);
		pthread_mutex_init(&philo[i].eat_mutex, NULL);
		i++;
	}
	return (0);
}
