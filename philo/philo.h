/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:17:28 by alejjime          #+#    #+#             */
/*   Updated: 2025/09/27 20:27:47 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>

typedef struct philo
{
	int	rank;
	int	eat;
	int	sleep;
	int	think;
	int	must_eat;
}		t_philo;

#endif
