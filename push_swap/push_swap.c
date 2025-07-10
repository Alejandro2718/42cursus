/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:20:39 by alejjime          #+#    #+#             */
/*   Updated: 2025/07/08 18:57:43 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		i;

	head_a = NULL;
	head_b = NULL;
	i = 1;
	// Comprobaciones de argumentos
	if (argc < 3)
	{
		ft_printf("Usage: %s <Numbers>\n", argv[0]);
		return (1);
	}
	// Comprobar que no hayan duplicados
	// create node and store the list
	while (i < argc)
	{
		if (check_arg(argv[i]))
		{
			// insert_end(&head, ft_atoi(argv[i]));
			i++;
		}
		else
		{
			free_list(head_a);
			return (0);
		}
	}
	if (int_duplicate(argv))
	{
		free_list(head_a);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		insert_end(&head_a, ft_atoi(argv[i]));
		insert_end(&head_b, ft_atoi(argv[i]));
		i++;
	}
	print_nodes(&head_a);
	print_nodes(&head_b);
	ss(&head_a, &head_b);
	print_nodes(&head_a);
	print_nodes(&head_b);
	free_list(head_a);
	return (0);
}
