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

void turk_algorithm(t_node **stack_a, t_node **stack_b)
{
	int n;
    if (!stack_a || !*stack_a)
        return;
    n = stack_size(*stack_a);
    if (n <= 3)
    {
        sort_three(stack_a);
        return;
    }
    if (is_sorted(*stack_a))
        return;
    push_all_but_three(stack_a, stack_b);
    sort_three(stack_a);
    while (stack_b && *stack_b)
    {
        update_index(*stack_a);
        update_index(*stack_b);
        set_above_median(*stack_a);
        set_above_median(*stack_b);
        calculate_push_costs(*stack_a, *stack_b);
        set_cheapest(*stack_b); // <-- Añadido para marcar el nodo más barato
        execute_cheapest_move(stack_a, stack_b);
        reset_cheapest(*stack_b);
    }
    final_rotation(stack_a);
}

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
	while (i < argc)
	{
		if (check_arg(argv[i]))
		{
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
		i++;
	}
	turk_algorithm(&head_a, &head_b);
	free_list(head_a);
	free_list(head_b);
	
	return (0);
}
