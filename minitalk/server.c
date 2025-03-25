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

void	get_1(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("message from client received: 1\n");
	
}

void	get_2(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("message from client received: 0\n");
	
}

int	main(void)
{
	int	server_pid;

	struct sigaction action_1, action_2;
	action_1.sa_handler = get_1;
	action_2.sa_handler = get_2;
  	sigemptyset(&action_1.sa_mask);
	sigemptyset(&action_2.sa_mask);
  	action_1.sa_flags = 0;
	action_2.sa_flags = 0;

	sigaction(SIGUSR1, &action_1, NULL);
	sigaction(SIGUSR2, &action_2, NULL);

	server_pid = getpid();
	ft_printf("PID: %i\n", server_pid);
	while (1)
	{
		pause();
	}
	return (0);
}
