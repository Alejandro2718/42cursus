/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:57:16 by alejjime          #+#    #+#             */
/*   Updated: 2026/03/15 17:57:16 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				n_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_philo_must_eat;
	int				dead_flag;
	long			start_time;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

typedef struct s_philo
{
	int				philo_index;
	int				meals_eat;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;

}	t_philo;

int		ft_atoi(const char *str);
int		parser(t_data *data, int argc, char **argv);
void	ft_usleep(int ms, t_philo *philo);
void	print_status(t_philo *philo, char *message);
int		check_dead(t_philo *philo);
long	get_time_ms(void);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	*philo_routine(void *arg);
void	*monitor_thread(void *arg);

#endif