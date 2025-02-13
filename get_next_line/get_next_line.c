/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:25 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/13 16:53:35 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	static size_t	bytes_read = 1;
	static int		position = 0;
	int				i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_clean_mem(buffer));
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	if ((size_t)position >= bytes_read)
		position = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		// printf("buffer: %s\n", buffer);
		i = 0;
		if (position == 0)
		{
			// bytes_read = read(fd, buffer, BUFFER_SIZE);
			// printf("\nCuando position = %i\nbuffer: %s\nbytes_read = %zu",
			// 	position, buffer, bytes_read);
			if (bytes_read == (size_t)(0))
			{
				line = malloc(2);
				line[i] = '\n';
				line[i + 1] = '\0';
				free(buffer);
				return (line);
			}
			if (bytes_read == (size_t)(-1))
				return (ft_clean_mem(buffer));
			buffer[bytes_read] = '\0';
		}
		line = malloc(bytes_read + 1);
		if (!line)
			return (ft_clean_mem(line));
		i = 0;
		while ((size_t)position < bytes_read + 1)
		{
			if (buffer[position] == '\n' || buffer[position] == '\0')
			{
				if (buffer[position] == '\n')
				{
					line[i] = '\n';
					line[i + 1] = '\0';
					position++;
					free(buffer);
					return (line);
				}
				else
				{
					line[i] = '\0';
					free(buffer);
					return (line);
				}
			}
			line[i++] = buffer[position++];
		}
	}
	free(buffer);
	return (NULL);
}
