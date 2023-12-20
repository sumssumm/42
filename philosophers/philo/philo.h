/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:17:15 by suminpar          #+#    #+#             */
/*   Updated: 2023/12/20 19:02:22 by suminpar         ###   ########.fr       */
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

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				left;
	int				right;
	int				eat_cnt;
	long			last_eat_time;
	pthread_t		thread;
	int				flag_finish;
	pthread_mutex_t	flag_finish_mutex;
	pthread_mutex_t	eat_mutex;
}	t_philo;

int		ph_atoi(char *str);
int		print_error(t_philo *philo, t_data *data, char *str);
long	get_time(void);
void	ft_usleep(long start, long sleep_time);
void	free_data_philo(t_philo *philo, t_data *data);

int		init_data(t_data *data, int argc, char **argv);
int		init_data_mutex(t_data *data);
int		init_philo(t_philo *philo, t_data *data);

int		create_threads(t_philo *philo, t_data *data);
void	*ph_thread(void *argv);
void	check_alive(t_philo *philo, t_data *data);
int		ph_dead_or_must_set(t_philo *philo, t_data *data, int *pos);
void	ph_stop_or_dead(t_philo *philo, t_data *data, int pos);

int		philo_eat(t_philo *philo, t_data *data);
int		philo_eat_even(t_philo *philo, t_data *data);
int		philo_eat_odd(t_philo *philo, t_data *data);
int		ph_left_fork_up(t_philo *philo, t_data *data);
int		ph_right_fork_up(t_philo *philo, t_data *data);

void	ph_behavior(t_philo *philo, t_data *data);
long	print_ph_state(t_philo *philo, int id, char *msg, int needtime);
void	philo_dead(t_philo *philo, t_data *data);
void	ph_fork_down(t_philo *philo, t_data *data);
int		philo_eat_set(t_philo *philo, t_data *data);

#endif