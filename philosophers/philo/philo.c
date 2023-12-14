/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:17:16 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/12 13:41:57 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < data->number_of_philo)
	{
		philo[i].data = data;
		philo[i].id = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->number_of_philo;
		philo[i].eat_cnt = 0;
		philo[i].last_eat_time = get_time(); //data->start_time
		i++;
	}
	return (philo);
}

int	create_philo_thread(t_philo *philo, t_data *data)
{

}