/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:39:44 by moel-yag          #+#    #+#             */
/*   Updated: 2025/06/29 15:09:01 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [number_of_meals]\n", av[0]);
		return 1;
	}
	if (!is_valid_arg(ac, av))
	{
		printf("Error\n");
		return (2);
	}
	printf("Philosopher simulation started.\n");
	
	// creating the number av[1] of of philosophers
	 
	t_philo philo;
	
	philo.id = 1;
	philo.meals_eaten = 0;
	philo.last_meal = get_time();
	pthread_mutex_t left_fork, right_fork;
	pthread_mutex_init(&left_fork, NULL);
	pthread_mutex_init(&right_fork, NULL);
	philo.left_fork = &left_fork;
	philo.right_fork = &right_fork;
	pthread_t thread;
	pthread_create(&thread, NULL, routine, (void *)&philo);
	pthread_join(thread, NULL);
	pthread_mutex_destroy(&left_fork);
	pthread_mutex_destroy(&right_fork);
	printf("Philosopher %d finished with %d meals eaten.\n", philo.id, philo.meals_eaten);
	printf("Simulation ended.\n");
	// Clean up and exit
	pthread_exit(NULL);
	return 0;
}