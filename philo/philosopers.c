/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:56:40 by alejjime          #+#    #+#             */
/*   Updated: 2026/03/15 18:46:13 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_state(t_data *data, int i, int *all_ate)
{
	pthread_mutex_lock(&data->dead_lock);
	if ((get_time_ms() - data->philos[i].last_meal_time) >= data->time_to_die)
	{
		data->dead_flag = 1;
		pthread_mutex_unlock(&data->dead_lock);
		pthread_mutex_lock(&data->write_lock);
		printf("%ld %d died\n", get_time_ms() - data->start_time,
			data->philos[i].philo_index);
		pthread_mutex_unlock(&data->write_lock);
		return (1);
	}
	if (data->num_of_times_philo_must_eat > 0
		&& data->philos[i].meals_eat < data->num_of_times_philo_must_eat)
		*all_ate = 0;
	pthread_mutex_unlock(&data->dead_lock);
	return (0);
}

int	parser(t_data *data, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num <= 0)
			return (1);
		i++;
	}
	data->n_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->num_of_times_philo_must_eat = -1;
	if (argc == 6)
		data->num_of_times_philo_must_eat = ft_atoi(argv[5]);
	data->dead_flag = 0;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	return (0);
}

void	*monitor_thread(void *arg)
{
	t_data	*data;
	int		i;
	int		all_ate;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		all_ate = 1;
		while (i < data->n_of_philosophers)
		{
			if (check_philo_state(data, i, &all_ate))
				return (NULL);
			i++;
		}
		if (data->num_of_times_philo_must_eat > 0 && all_ate)
			return (pthread_mutex_lock(&data->dead_lock), data->dead_flag = 1,
				pthread_mutex_unlock(&data->dead_lock), NULL);
		usleep(500);
	}
}

static int	init_simulation(t_data *data)
{
	t_philo		*philos;
	int			i;

	philos = malloc(sizeof(t_philo) * data->n_of_philosophers);
	if (!philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_of_philosophers);
	if (!data->forks)
		return (free(philos), 1);
	data->philos = philos;
	data->start_time = get_time_ms();
	i = 0;
	while (i < data->n_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		philos[i].data = data;
		philos[i].philo_index = i + 1;
		philos[i].meals_eat = 0;
		philos[i].last_meal_time = get_time_ms();
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->n_of_philosophers];
		pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor;
	int			i;

	if (argc < 5 || argc > 6)
		return (printf("Correct use: ./philo n_philo t_die "
				"t_eat t_sleep n_t_each_philo_must_eat\n"), 1);
	if (parser(&data, argc, argv))
		return (1);
	if (init_simulation(&data))
		return (1);
	pthread_create(&monitor, NULL, monitor_thread, &data);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data.n_of_philosophers)
	{
		pthread_join(data.philos[i].thread, NULL);
		pthread_mutex_destroy(&data.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data.dead_lock);
	pthread_mutex_destroy(&data.write_lock);
	return (free(data.forks), free(data.philos), 0);
}
