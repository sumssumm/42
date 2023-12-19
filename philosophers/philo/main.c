#include "philo.h"

void	check_leak(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if ((argc != 5 && argc != 6))
		return (print_error("need 5 or 6 arguments"));
	data = malloc(sizeof(t_data));
	if (data == NULL || init_data(data, argc, argv))
		return (print_error("data init"));
	philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (philo == NULL || init_philo(philo, data))
		return (print_error("philo init"));
	if (create_threads(philo, data))
		return (print_error("create threads"));
	free_data_philo(philo, data);
	return (0);
}
