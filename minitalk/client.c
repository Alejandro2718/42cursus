/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:40:45 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/02 17:25:48 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	print_binary(int pid, unsigned char ch)
{
	int	bit_signal;
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((ch & (1 << i)) != 0)
		{
			bit_signal = 1;
			kill(pid, SIGUSR1);
		}
		else
		{
			bit_signal = 0;
			kill(pid, SIGUSR2);
		}
		usleep(1000);
		i--;
	}
}

int	main(int argc, char **argv)
{
	char *message;
	int server_pid;

	if (argc != 3 || !argv[2])
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}

	server_pid = ft_atoi(argv[1]);
	message = argv[2];

	ft_printf("Server PID: %i\n", server_pid);
	ft_printf("Message sent: %s\n", message);

	while (*message)
	{
		print_binary(server_pid, *message);
		message++;
	}

	return (0);
}