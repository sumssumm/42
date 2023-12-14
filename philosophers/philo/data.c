#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philo = ph_atoi(argv[1]);
	data->time_to_die = ph_atoi(argv[2]);
	data->time_to_eat = ph_atoi(argv[3]);
	data->time_to_sleep = ph_atoi(argv[4]);
	data->must_eat = 0;
	data->start_time = get_time();
	if (data->start_time == -1)
		return (1);
	if (argc == 6)
	{
		data->must_eat = ph_atoi(argv[5]);
		if (data->must_eat <= 0 || data->must_eat > 2147483647)
			return (1);
	}
	if (check_data(data) == 1)
		return (1);
	if (init_data_mutex(data) == 1)
		return (1);
	return (0);
}

int	check_data(t_data *data)
{
	if (data->number_of_philo <= 0 || data->time_to_die < 0 \
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (1);
	else if (data->number_of_philo > 2147483647 || data->time_to_die > 2147483647 \
		|| data->time_to_eat > 2147483647 || data->time_to_sleep > 2147483647)
		return (1);
	return (0);
}

int	init_data_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&(data->print), NULL) != 0)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (data->forks == NULL)
		return (1);
	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0);
			return (1);
		i++;
	}
	return (0);
}