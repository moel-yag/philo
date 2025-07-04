/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:40:00 by moel-yag          #+#    #+#             */
/*   Updated: 2025/07/02 21:10:45 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*stop_mutex;
	int				id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		threads;
	int				*stop;
}					t_philo;

long long			get_time(void);
void				*routine(void *arg);
bool				is_valid_arg(int ac, char *args[]);
long long			ft_atoi(const char *str);

#endif