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

void handle_signal(int signum, siginfo_t *info, void *context)
{
    static unsigned char current_byte = 0;
    static int bits_received = 0;
    int bit_value;

    (void)context; // No se utiliza
    // Determinamos el bit recibido según la señal
    if (signum == SIGUSR1)
        bit_value = 1;
    else
        bit_value = 0;

    current_byte = (current_byte << 1) | bit_value;
    bits_received++;

    if (bits_received == 8)
    {
        if (current_byte == '\0')
        {
            // Si el carácter es nulo, el mensaje completo ha sido recibido,
            // se envía una señal de confirmación al cliente.
            kill(info->si_pid, SIGUSR1);
        }
        else
        {
            // Imprime el carácter recibido
            ft_putchar_fd(current_byte, 1);
        }
        current_byte = 0;
        bits_received = 0;
    }
}


int main(void)
{
    int server_pid;
    struct sigaction sa;

    // Set up the sigaction structure for SA_SIGINFO
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sa.sa_flags = SA_RESTART | SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
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
