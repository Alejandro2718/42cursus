/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:25 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/28 18:51:20 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*save_in_storage(int fd, char *storage, int bytes_read)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && (!storage || !ft_strchr(storage, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (storage)
				free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer, -1);
		if (!storage)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (storage);
}

static char	*get_line(char *storage)
{
	char	*line;
	size_t	len;
	size_t	i;

	i = 0;
	if (!storage || !storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	len = i;
	if (storage[i] == '\n')
		len++;
	line = ft_substr(storage, 0, len);
	return (line);
}

static char	*upd_storage(char *storage)
{
	char	*new_stor;
	size_t	i;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_stor = ft_substr(storage, i + 1, ft_strlen(storage) - i - 1);
	free(storage);
	return (new_stor);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = save_in_storage(fd, storage, 1);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = upd_storage(storage);
	return (line);
}
