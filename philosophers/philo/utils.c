#include "philo.h"

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

void	ft_usleep(long sleep_time, t_data *data)
{
	long	start;
	long	now;

	start = get_time();
	while (!(data->flag_finish))
	{
		now = get_time();
		if (now - start + 10 < sleep_time)
			usleep(500);
		else if (now - start >= sleep_time)
			break ;
		else
			usleep(50);
	}
}