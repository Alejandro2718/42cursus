/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:45:37 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/22 18:24:54 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	// int		i;
	// ssize_t	bytes;
	// char	*line;
	fd = open("prueba.txt", O_RDONLY);
	for (size_t i = 0; i < 3; i++)
	{
		line = malloc(100);
		line = get_next_line(fd);
		printf("\nline: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
