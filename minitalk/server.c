/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:40:42 by alejjime          #+#    #+#             */
/*   Updated: 2025/03/10 16:57:04 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

void	get_message_from_client(int sig)
{
	volatile sig_atomic_t	signal_code;

	signal_code = sig;
	ft_printf("message from client received: \n");
}

int	main(void)
{
	int	server_pid;

	signal(SIGUSR1, get_message_from_client);
	signal(SIGUSR2, get_message_from_client);
	signal(SIGTERM, get_message_from_client);
	server_pid = getpid();
	ft_printf("PID: %i\n", server_pid);
	while (1)
	{
		pause();
	}
	return (0);
}
