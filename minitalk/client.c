/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:40:45 by alejjime          #+#    #+#             */
/*   Updated: 2025/03/10 16:57:35 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>
#include <unistd.h>

void print_binary(int pid, unsigned char ch) {
    for (int i = 7; i >= 0; i--) {
        // Send signal based on bit value (0 or 1)
        int bit_signal = (ch & (1 << i)) ? 1 : 0;
        
        if (bit_signal == 1) {
            kill(pid, SIGUSR1);  // Signal for bit 1
        } else {
            kill(pid, SIGUSR2);  // Signal for bit 0
        }
        
        // Add a small delay between signals to ensure they are processed
        usleep(100);  // 100ms delay
    }
}

int main(int argc, char **argv)
{
    if (argc != 3 || !argv[2]) {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return (1);
    }

    int server_pid = ft_atoi(argv[1]);
    char *message = argv[2];

    ft_printf("Server PID: %i\n", server_pid);
    ft_printf("Message sent: %s\n", message);

    // Send each character of the message
    while (*message) {
        print_binary(server_pid, *message);
        message++;
    }
    
    return (0);
}