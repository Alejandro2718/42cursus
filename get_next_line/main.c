/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:45:37 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/13 15:44:50 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	for (int i = 0; i < 1; i++)
	{
		printf("\n\n\n\n%s\n", get_next_line(fd));
	}
	close(fd);
	return (0);
}
