/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:25 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/19 18:33:25 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*line;
	static char		buffer[BUFFER_SIZE];
	static int		position;
	static ssize_t	bytes_read;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	if (position == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == (ssize_t)(-1))
		{
			return (NULL);
		}
	}
	if (buffer[0] == '\0')
		return (NULL);
	// if (buffer[0] == '\n' && buffer[1] == '\0')
	// {
	// 	line = malloc(2);
	// 	line[0] = '\n';
	// 	line[1] = '\0';
	// 	return (line);
	// }
	line = malloc(bytes_read + 1);
	if (!line)
	{
		position = 0;
		return (NULL);
	}
	i = 0;
	while ((ssize_t)position < bytes_read && buffer[position])
	{
		if (buffer[position] == '\n')
		{
			line[i] = '\n';
			line[i + 1] = '\0';
			position++;
			return (line);
		}
		else if (buffer[position] == '\0')
		{
			line[i] = '\0';
			return (line);
		}
		line[i++] = buffer[position++];
	}
	if ((ssize_t)position >= bytes_read)
	{
		position = 0;
	}
	line[i] = '\0';
	return (line);
}
