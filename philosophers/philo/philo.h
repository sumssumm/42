/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:17:15 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/18 14:00:09 by suminpar         ###   ########.fr       */
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
	int				flag_finish;
	int				eat_all;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
} t_data;

typedef struct	s_philo
{
	t_data			*data;
	int				id;
	int				left;
	int				right;
	int				eat_cnt;
	int				flag_finish;
	long			last_eat_time;
	pthread_t		thread;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	flag_finish_mutex;
} t_philo;

int		ph_atoi(char *str);
int		print_error(char *str);
long	get_time(void);
void	ft_usleep(long sleep_time, t_data *data);

int		init_data(t_data *data, int argc, char **argv);
int		init_data_mutex(t_data *data);
int		init_philo(t_philo *philo, t_data *data);

int		create_threads(t_philo *philo, t_data *data);
void	*ph_thread(void *argv);
int		philo_eat_even(t_philo *philo, t_data *data);
int		philo_eat_odd(t_philo *philo, t_data *data);
// int		philo_eat(t_philo *philo, t_data *data);
int		print_ph_state(t_philo *philo, int id, char *msg);
void	check_finish(t_philo *philo, t_data *data);


#endif