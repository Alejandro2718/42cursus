/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:25:19 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/22 18:06:23 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// char	*get_line(char *buffer, ssize_t position, ssize_t bytes_read)
// {
// 	char	*line;
// 	int		i;

// 	line = malloc(bytes_read + 1);
// 	if (!line)
// 	{
// 		position = 0;
// 		printf("line NULL:\n");
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (position < bytes_read)
// 	{
// 		if (buffer[position] == '\n')
// 		{
// 			line[i] = '\n';
// 			line[i + 1] = '\0';
// 			position++;
// 			printf(" n Return:\n");
// 			return (line);
// 		}
// 		else if (buffer[position] == '\0')
// 		{
// 			line[i] = '\0';
// 			printf(" 0 Return:\n");
// 			return (line);
// 		}
// 		line[i++] = buffer[position++];
// 	}
// 	if (position >= bytes_read)
// 	{
// 		position = 0;
// 	}
// 	line[i] = '\0';
// 	printf("Ultimo returnde programa:\n");
// 	return (line);
// }
