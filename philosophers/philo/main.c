/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:53:45 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/21 01:18:54 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if ((argc != 5 && argc != 6))
		return (print_error(NULL, NULL, "need 5 or 6 arguments"));
	data = malloc(sizeof(t_data));
	if (data == NULL || !memset(data, 0, sizeof(t_data)) \
		|| init_data(data, argc, argv))
		return (print_error(NULL, data, "data init"));
	philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (philo == NULL || !memset(philo, 0, sizeof(t_philo)) \
		|| init_philo(philo, data))
		return (print_error(philo, data, "philo init"));
	if (create_threads(philo, data))
		return (print_error(philo, data, "create threads"));
	free_data_philo(philo, data);
	return (0);
}
