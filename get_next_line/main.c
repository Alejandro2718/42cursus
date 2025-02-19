/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:45:37 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/19 18:34:53 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	// printf("\n\n\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s", get_next_line(fd));
	}
	// printf("\n");
	close(fd);
	return (0);
}
