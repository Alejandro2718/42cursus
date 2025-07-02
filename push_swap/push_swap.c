/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:20:39 by alejjime          #+#    #+#             */
/*   Updated: 2025/07/02 19:49:26 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;
	int		i;

	head = NULL;
	i = 1;
	// Comprobaciones de argumentos
	if (argc < 3)
	{
		ft_printf("Usage: %s <Numbers>\n", argv[0]);
		return (1);
	}
	// Comprobaciones logicas (is int?, max_int?)
	// create node and store the list
	while (i < argc)
	{
		if (check_arg(argv[i]))
		{
			// ft_printf("Node[%i]: %s\n", i, argv[i]);
			insert_end(&head, ft_atoi(argv[i]));
			i++;
		}
		else
		{
			// ft_printf("Error\n");
			free_list(head);
			return (0);
		}
	}
	print_nodes(&head);
	free_list(head);
	return (0);
}
