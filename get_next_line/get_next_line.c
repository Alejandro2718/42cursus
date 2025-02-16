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

char *get_next_line(int fd)
{
    char *line;
    static char *buffer = NULL;
    static int position = 0;
    static ssize_t bytes_read = 0;
    int i = 0;

    if (!buffer)
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buffer);
            buffer = NULL;
            return (NULL);
        }
        buffer[bytes_read] = '\0';
    }
    /* Allocate only enough memory for the remainder of the buffer */
    line = malloc((bytes_read - position) + 1);
    if (!line)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    while (position < bytes_read)
    {
        line[i] = buffer[position];
        if (buffer[position] == '\n')
        {
            i++;
            position++;
            line[i] = '\0';
            /* If we’ve reached the end of the buffer, free it */
            if (position >= bytes_read)
            {
                free(buffer);
                buffer = NULL;
                position = 0;
            }
            return (line);
        }
        i++;
        position++;
    }
    line[i] = '\0';
    /* End of file reached: free the static buffer */
    free(buffer);
    buffer = NULL;
    position = 0;
    return (line);
}

