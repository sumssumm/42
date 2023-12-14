/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:17:15 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/12 13:41:16 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> //printf
# include <stdlib.h> //malloc, free
# include <string.h> //memset
# include <unistd.h> //write, usleep 
# include <pthread.h> //pthread
# include <sys/time.h> //gettimeofday

typedef struct	s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
} t_data;

typedef struct	s_philo
{
	t_data		*data;
	int			id;
	int			left_fork;
	int			right_fork;
	int			eat_cnt;
	long		last_eat_time;
	pthread_t	tid;
} t_philo;

int	ph_atoi(char *str);
int	print_error();
int	check_argv(char **argv);
int	ft_free(t_data *data, t_philo *philo);

int	init_data(t_data *data, int argc, char **argv);
int	check_data(t_data *data);
int	init_data_mutex(t_data *data);

t_philo	*init_philo(t_data *data);
int	create_philo_threads(t_philo *philo, t_data *data);



#endif