/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:39:48 by moel-yag          #+#    #+#             */
/*   Updated: 2025/07/02 17:13:50 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	long long	the_time;

	philo = (t_philo *)arg;
	the_time = get_time();
	pthread_mutex_lock(philo->stop_mutex);
	if (*(philo->stop))
	{
		pthread_mutex_unlock(philo->stop_mutex);
		return (NULL);
	}
	while (1)
	{
		printf("%lld %d is thinking.\n",the_time, philo->id);
		usleep(1000);
		pthread_mutex_lock(philo->left_fork);
		printf("%lld %d picked up left fork.\n",the_time, philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("%lld %d picked up right fork.\n",the_time, philo->id);
		printf("%lld %d is eating.\n",the_time, philo->id);
		usleep(1000);
		pthread_mutex_unlock(philo->stop_mutex);
		philo->meals_eaten++;
		philo->last_meal = get_time();
		pthread_mutex_unlock(philo->right_fork);
		printf("%lld %d put down right fork.\n",the_time, philo->id);
		pthread_mutex_unlock(philo->left_fork);
		printf("%lld %d put down left fork.\n",the_time, philo->id);
		printf("%lld %d is sleeping.\n",the_time, philo->id);
		// pthread_mutex_lock(philo->stop_mutex);
		// if (*(philo->stop))
		// {
		// 	pthread_mutex_unlock(philo->stop_mutex);
		// 	break ;
		// }
		usleep(1000);
	}
	return (NULL);
}
