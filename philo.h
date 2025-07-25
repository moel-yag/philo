/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:40:00 by moel-yag          #+#    #+#             */
/*   Updated: 2025/07/13 18:53:35 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	int				leftfork_id;
	int				rightfork_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_t		threads;
	int				id;
	int				meals_eaten;
	long long		last_meal;
	long long		start_time;
	int				*stop;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
}					t_philo;

typedef struct s_sim
{
	t_philo			*philos;
	int				num_philo;
	int				time_to_die;
	int				meal_target;
	int				*stop;
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*print_mutex;
}					t_sim;

typedef struct s_cleanup_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*print_mutex;
	int				num_philo;
}				t_cleanup_data;

typedef struct s_main_data
{
	t_philo			philos[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
	t_sim			sim;
	pthread_t		monitor_thread;
	int				stop;
	int				num_philo;
}				t_main_data;

long long			get_time(void);
void				check_death(t_sim *sim, int i);
void				*routine(void *arg);
bool				is_valid_arg(int ac, char *args[]);
long long			ft_atoi(const char *str);
void				*monitor(void *arg);
void				print_status(t_philo *philo, const char *status);
void				precise_usleep(long duration, t_philo *philo);
void				cleanup(t_cleanup_data *data);

#endif
