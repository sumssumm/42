#include "philo.h"

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if ((argc != 5 && argc != 6))
		return (print_error("need 5 or 6 args"));
	data = malloc(sizeof(t_data));
	if (data == NULL || init_data(data, argc, argv) == 1)
		return (print_error("data init"));
	philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (philo == NULL || init_philo(philo, data) == 1)
		return (print_error("philo init"));
	if (create_threads(philo, data) == 1)
		return (print_error("create threads"));
	return (0);
}

int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}
