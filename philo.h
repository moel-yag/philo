/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:40:00 by moel-yag          #+#    #+#             */
/*   Updated: 2025/07/01 12:00:23 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <errno.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;  // Timestamp of the last meal
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

long long	get_time(void);
void		*routine(void *arg);
bool		is_valid_arg(int ac, char *args[]);
long long	ft_atoi(const char *str);


#endif