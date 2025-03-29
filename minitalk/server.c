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

// Global variables to keep track of bits
unsigned char g_current_byte = 0;
int g_bits_received = 0;

void handle_bit(int bit_value)
{
    // Shift the current byte left and add the new bit
    g_current_byte = (g_current_byte << 1) | bit_value;
    g_bits_received++;
    
    // If we have received 8 bits (a complete byte)
    if (g_bits_received == 8)
    {
        // Print the character
        ft_printf("Character received: %c\n", g_current_byte);
        
        // Reset for the next character
        g_current_byte = 0;
        g_bits_received = 0;
    }
}

void get_1(int sig)
{
    if (sig == SIGUSR1)
    {
        // ft_printf("Bit received: 1\n");
        handle_bit(1);
    }
}

void get_0(int sig)
{
    if (sig == SIGUSR2)
    {
        // ft_printf("Bit received: 0\n");
        handle_bit(0);
    }
}

int	main(void)
{
	int	server_pid;

	struct sigaction action_1, action_2;
	action_1.sa_handler = get_1;
	action_2.sa_handler = get_0;
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
