/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:25 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/22 18:36:07 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	get_car(int fd)
{
	char	*car;

	read(fd, car, 1);
	car[1] = '\0';
	return (car[0]);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	car;
	int		i;

	// Primero condiciones de NULL si no se puede abrir o es menor a lo necesario
	i = 0;
	line = malloc(2);
	while (car != '\0')
	{
		car = get_car(fd);
		line[i] = car;
		i++;
	}
	line[i] = '\0';
	return (line);
}
