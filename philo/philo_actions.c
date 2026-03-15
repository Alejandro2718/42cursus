/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:28:41 by alejjime          #+#    #+#             */
/*   Updated: 2026/03/15 18:32:20 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	long	think_time;

	print_status(philo, "is thinking\n");
	if (philo->data->n_of_philosophers % 2 != 0)
	{
		think_time = (philo->data->time_to_eat * 2)
			- philo->data->time_to_sleep;
		if (think_time < 0)
			think_time = 0;
		ft_usleep(think_time, philo);
	}
}

void	eat(t_philo *philo)
{
	if (philo->philo_index % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork\n");
	}
	pthread_mutex_lock(&philo->data->dead_lock);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->data->dead_lock);
	print_status(philo, "is eating\n");
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_lock(&philo->data->dead_lock);
	philo->meals_eat++;
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep, philo);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_of_philosophers == 1)
	{
		print_status(philo, "has taken a fork\n");
		ft_usleep(philo->data->time_to_die, philo);
		return (NULL);
	}
	if (philo->philo_index % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2, philo);
	while (!check_dead(philo))
	{
		think(philo);
		if (check_dead(philo))
			break ;
		eat(philo);
		if (check_dead(philo))
			break ;
		philo_sleep(philo);
	}
	return (NULL);
}
