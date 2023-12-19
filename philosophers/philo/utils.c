#include "philo.h"

int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

void	free_data_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print_mutex);
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_destroy(&data->forks[i]) || \
			pthread_mutex_destroy(&philo[i].flag_finish_mutex) || \
			pthread_mutex_destroy(&philo[i].eat_mutex))
		{
			printf("%d\n", i);
		}
		i++;
	}
	free(data->forks);
	free(data);
	free(philo);
}

int	ph_atoi(char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (result > 2147483647 || result < -2147483648)
		return (-1);
	return (result * sign);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long start, long sleep_time)
{
	long	now;

	while (1)
	{
		now = get_time();
		if (now - start > sleep_time)
			printf("%30ld\n", now - start);
		if (now - start + 10 < sleep_time)
			usleep(2000);
		else if (now - start >= sleep_time)
			break ;
		usleep(100);
	}
}
