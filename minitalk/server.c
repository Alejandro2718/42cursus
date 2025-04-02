/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:40:42 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/02 17:34:03 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

// Global variables to keep track of bits
unsigned char	g_current_byte = 0;
int				g_bits_received = 0;

void	handle_signal(int signum)
{
	int	bit_value;

	if (signum == SIGUSR1)
		bit_value = 1;
	else
		bit_value = 0;
	g_current_byte = (g_current_byte << 1) | bit_value;
	g_bits_received++;
	if (g_bits_received == 8)
	{
		// ft_printf("%c", g_current_byte);
		ft_putchar_fd(g_current_byte, 1);
		g_current_byte = 0;
		g_bits_received = 0;
	}
}

int	main(void)
{
	int					server_pid;
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		ft_printf("Error setting up signal handlers\n");
		return (1);
	}
	server_pid = getpid();
	ft_printf("PID: %i\n", server_pid);
	while (1)
	{
		pause();
	}
	return (0);
}
