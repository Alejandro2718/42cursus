/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:11:55 by alejjime          #+#    #+#             */
/*   Updated: 2026/03/15 18:27:46 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	temp;

	i = 0;
	sign = 1;
	temp = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + (str[i] - '0');
		i++;
	}
	return (temp * sign);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	check_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->data->dead_lock);
	dead = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (dead);
}

void	ft_usleep(int ms, t_philo *philo)
{
	long	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < ms)
	{
		if (check_dead(philo))
		{
			break ;
		}
		usleep(100);
	}
}

void	print_status(t_philo *philo, char *message)
{
	long	time_stamp;

	pthread_mutex_lock(&philo->data->write_lock);
	time_stamp = get_time_ms() - philo->data->start_time;
	if (!philo->data->dead_flag)
		printf("%ld %d %s", time_stamp, philo->philo_index, message);
	pthread_mutex_unlock(&philo->data->write_lock);
}
