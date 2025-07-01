/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:39:44 by moel-yag          #+#    #+#             */
/*   Updated: 2025/07/01 16:20:01 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

int	main(int ac, char **av)
{
    t_philo			*philosophers;
    pthread_mutex_t	*forks;
    pthread_t		*threads;
    int				num_philosophers;
    int				i;

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
    num_philosophers = ft_atoi(av[1]);
    philosophers = malloc(num_philosophers * sizeof(t_philo));
    forks = malloc(num_philosophers * sizeof(pthread_mutex_t));
    threads = malloc(num_philosophers * sizeof(pthread_t));
    if (!philosophers || !forks || !threads)
        return (printf("Memory allocation failed.\n"), 3);
    i = 0;
    while (i < num_philosophers)
        pthread_mutex_init(&forks[i++], NULL);
    i = 0;
    while (i < num_philosophers)
    {
        philosophers[i].id = i + 1;
        philosophers[i].meals_eaten = 0;
        philosophers[i].last_meal = get_time();
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % num_philosophers];
        pthread_create(&threads[i], NULL, routine, &philosophers[i]);
        i++;
    }
    i = 0;
    while (i < num_philosophers)
        pthread_join(threads[i++], NULL);
    i = 0;
    while (i < num_philosophers)
        pthread_mutex_destroy(&forks[i++]);
    free(philosophers);
    free(forks);
    free(threads);
    return (0);
}

// int main(int ac, char **av)
// {
// 	if (ac != 5 && ac != 6)
// 	{
// 		printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat>
// <time_to_sleep> [number_of_meals]\n", av[0]);
// 		return 1;
// 	}
// 	if (!is_valid_arg(ac, av))
// 	{
// 		printf("Error\n");
// 		return (2);
// 	}
// 	printf("Philosopher simulation started.\n");
	
// 	// creating the ft_atoi(av[1]) of philosophers
// 	t_philo *philosophers;
// 	int num_philosophers = ft_atoi(av[1]);
// 	philosophers = malloc(num_philosophers * sizeof(t_philo));
// 	if (!philosophers)
// 	{
// 		printf("Memory allocation failed.\n");
// 		return 3;
// 	}
// 	pthread_mutex_t *forks = malloc(num_philosophers * sizeof(pthread_mutex_t));
	
// 	if (!forks)
// 	{
// 		printf("Memory allocation for forks failed.\n");
// 		free(philosophers);
// 		return 4;
// 	}
// 	int i = 0;
// 	while (i < num_philosophers)
// 	{
// 		philosophers[i].id = i + 1;
// 		philosophers[i].meals_eaten = 0;
// 		philosophers[i].last_meal = get_time();
// 		pthread_mutex_t *left_fork = malloc(sizeof(pthread_mutex_t));
// 		pthread_mutex_t *right_fork = malloc(sizeof(pthread_mutex_t));
// 		if (!left_fork || !right_fork)
// 		{
// 			printf("Memory allocation for forks failed.\n");
// 			free(philosophers);
// 			return 4;
// 		}
// 		pthread_mutex_init(left_fork, NULL);
// 		pthread_mutex_init(right_fork, NULL);
// 		philosophers[i].left_fork = left_fork;
// 		philosophers[i].right_fork = right_fork;
		
// 		pthread_t thread;
// 		pthread_create(&thread, NULL, routine, (void *)&philosophers[i]);
// 		// pthread_detach(thread); // Detach the thread to avoid memory leaks
// 		// int j = 0;
// 		// while (j < num_philosophers)
// 		// {
// 		pthread_mutex_destroy(philosophers[i].left_fork);
// 		pthread_mutex_destroy(philosophers[i].right_fork);
// 		free(philosophers[i].left_fork);
// 		free(philosophers[i].right_fork);
// 		// j++;
// 		// }
// 		i++;
// 		usleep(1000000); // 1 second
// 	}
// 	// Wait for a while to let philosophers run (this is just for demonstration)
// 	// Clean up
// 	// i = 0;
// 	free(philosophers);
// 	printf("Philosopher simulation ended.\n");

// 	// int i = 1;
// 	// while (i <= (int )ft_atoi(av[1]))
// 	// {
// 	// 	printf("Philosopher %d is created.\n", i + 1);
// 	// 	i++;
// 	// }
		
// 	// t_philo philo;
	
// 	// philo.id = i;
// 	// philo.meals_eaten = 0;
// 	// philo.last_meal = get_time();
// 	// pthread_mutex_t left_fork, right_fork;
// 	// pthread_mutex_init(&left_fork, NULL);
// 	// pthread_mutex_init(&right_fork, NULL);
// 	// philo.left_fork = &left_fork;
// 	// philo.right_fork = &right_fork;
// 	// pthread_t thread;
// 	// pthread_create(&thread, NULL, routine, (void *)&philo);
// 	// pthread_join(thread, NULL);
// 	// pthread_mutex_destroy(&left_fork);
// 	// pthread_mutex_destroy(&right_fork);
// 	// printf("Philosopher %d finished with %d meals eaten.\n", philo.id, philo.meals_eaten);
// 	// printf("Simulation ended.\n");
// 	// // Clean up and exit
// 	// pthread_exit(NULL);
	
// 	return 0;
// }
