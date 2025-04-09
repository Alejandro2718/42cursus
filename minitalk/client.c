/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:40:45 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/09 14:56:37 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	confirmation_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Mensaje received from server!\n");
		exit(0);
	}
}

void	print_binary(int pid, unsigned char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((ch & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	char				*message;
	int					server_pid;

	if (argc != 3 || !argv[2])
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	sa.sa_handler = confirmation_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("Server PID: %i\n", server_pid);
	ft_printf("Message sent: %s\n", message);
	while (*message)
	{
		print_binary(server_pid, *message);
		message++;
	}
	print_binary(server_pid, '\0');
	pause();
	return (0);
}
