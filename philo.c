/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:39:44 by moel-yag          #+#    #+#             */
/*   Updated: 2025/07/02 17:03:06 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	stop_mutex;
	int				stop;
	int				num_philo;
	int				i;

	stop = 0;
	if (ac != 5 && ac != 6)
	{
		printf("Usage: %s <number_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [number_of_meals]\n",
				av[0]);
		return (1);
	}
	if (!is_valid_arg(ac, av))
	{
		printf("Error\n");
		return (2);
	}
	num_philo = ft_atoi(av[1]);
	i = 0;
	stop = 0;
	pthread_mutex_init(&stop_mutex, NULL);
	while (i < num_philo)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	while (i < num_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = get_time();
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % num_philo];
		philo[i].stop = &stop;
		philo[i].stop_mutex = &stop_mutex;
		pthread_create(&philo[i].threads, NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < num_philo)
	{
		pthread_join(philo[i].threads, NULL);
		i++;	
	}
	i = 0;
	while (i < num_philo)
		pthread_mutex_destroy(&forks[i++]);
	return (0);
}
