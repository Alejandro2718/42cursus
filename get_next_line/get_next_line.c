/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:25 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/10 14:06:25 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;
	static int		position;
	static size_t	bytes_read;
	int				i;

	if (position == 0)
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if ((int)bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
	}
	line = malloc(bytes_read + 1);
	if (!line)
	{
		free(buffer);
		free(line);
		printf("Fallo line\n");
		return (NULL);
	}
	i = 0;
	while (position <= bytes_read)
	{
		if (buffer[position] == '\n' || buffer[position] == '\0')
		{
			if (buffer[position] == '\n')
			{
				line[i] = '\n';
				line[i + 1] = '\0';
			}
			else
			{
				line[i] = '\0';
			}
			position++;
			return (line);
		}
		line[i] = buffer[position];
		i++;
		position++;
	}
	free(buffer);
	free(line);
	return (NULL);
}
