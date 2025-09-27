/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:17:34 by alejjime          #+#    #+#             */
/*   Updated: 2025/09/27 20:54:21 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Each philosopher must be represented as a separate thread.
*/

/*
There is one fork between each pair of philosophers. Therefore,
if there are several philosophers,each philosopher has a fork on
their left side and a fork on their right side.
If there is only one philosopher, they will have access to just one fork.
*/

/*
To prevent philosophers from duplicating forks,
you should protect each fork’s state with a mutex
*/

#include "philo.h"

void	*foo(void *arg)
{
	(void)arg;
	printf("Created a new thread\n");
	return (NULL);
}

void	create_philo_and_forks(int num_philo)
{
}
// ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>
// [number_of_times_each_philo_must_eat]

int	main(int argc, char **argv)
{
	pthread_t	thread1;
	char		*num_philo;
	char		*time_to_die;
	char		*time_to_eat;
	char		*time_to_sleep;

	if (argc < 4 || argc > 5)
		return (0);
	num_philo = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	time_to_eat = ft_atoi(argv[3]);
	time_to_sleep = ft_atoi(argv[4]);
	pthread_create(&thread1, NULL, foo, NULL);
	pthread_join(thread1, NULL);
	return (0);
}
