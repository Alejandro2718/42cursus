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
	if (sig == 10)
		ft_printf("message from client received: 0\n");
	else if (sig == 12)
		ft_printf("message from client received: 1\n");
}

int	main(void)
{
	int	server_pid;

	struct sigaction action;
  	action.sa_handler = get_message_from_client;
  	sigemptyset(&action.sa_mask);
  	action.sa_flags = 0;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	server_pid = getpid();
	ft_printf("PID: %i\n", server_pid);
	while (1)
	{
		pause();
	}
	return (0);
}
