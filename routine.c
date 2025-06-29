/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:39:48 by moel-yag          #+#    #+#             */
/*   Updated: 2025/06/29 15:04:43 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); // time in milliseconds
}

void    *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1)
	{
		printf("Philosopher %d is thinking.\n", philo->id);
		usleep(1000);

		pthread_mutex_lock(philo->left_fork);
		printf("Philosopher %d picked up left fork.\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("Philosopher %d picked up right fork.\n", philo->id);
		printf("Philosopher %d is eating.\n", philo->id);
		usleep(1000);
		philo->meals_eaten++;
		philo->last_meal = get_time(); // Update last meal time

		pthread_mutex_unlock(philo->right_fork);
		printf("Philosopher %d put down right fork.\n", philo->id);
		pthread_mutex_unlock(philo->left_fork);
		printf("Philosopher %d put down left fork.\n", philo->id);

		printf("Philosopher %d is sleeping.\n", philo->id);
		usleep(1000);
	}
	return (NULL);
}
