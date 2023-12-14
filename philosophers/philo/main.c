#include "philo.h"

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (check_argv(argv) == 1 || (argc != 5 && argc != 6))
		return (print_error());
	data = malloc(sizeof(t_data));
	if (data == NULL || init_data(data, argc, argv) == 1)
		return (ft_free(data, NULL));
	philo = init_philo(data);
	if (philo == NULL)
		return (ft_free(data, philo));
	if (create_philo_threads(philo, data) == 1)
		return (ft_free(data, philo));
	return (0);
}
