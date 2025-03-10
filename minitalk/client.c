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

int	main(int argc, char **argv)
{
	if (argc != 3 || !argv[2])
		return (1);
	ft_printf("Server PID: %i\n", ft_atoi(argv[1]));
	ft_printf("Message sent: %s\n", argv[2]);
	kill((int)argv[1][0], SIGUSR1);
}
