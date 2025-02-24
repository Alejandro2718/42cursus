/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:25 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/24 16:43:42 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	get_car(int fd, char *buffer)
{
	static int	index = 0;
	static int	bytes_read = 0;
	char		car;

	// car = malloc(sizeof(char));
	// if (!car)
	// 	return (NULL);
	if (index >= bytes_read)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read <= 0)
		{
			// free(car);
			return (0);
		}
		index = 0;
	}
	car = buffer[index];
	index++;
	return (car);
}

char	*create_line(int fd, char *buffer)
{
	char	*line;
	int		y;
	char	car;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	y = 0;
	while ((car = get_car(fd, buffer)))
	{
		line[y++] = car;
		// free(car);
		if (car == '\n')
		{
			line[y] = '\0';
			return (line);
		}
	}
	if (y > 0)
	{
		line[y] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
	}
	line = create_line(fd, buffer);
	// Free buffer only if no more lines can be read
	if (!line)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
