/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:20:39 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 21:08:47 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_b_cycle(t_node **stack_a, t_node **stack_b)
{
	update_index(*stack_a);
	update_index(*stack_b);
	set_above_median(*stack_a);
	set_above_median(*stack_b);
	calculate_push_costs(*stack_a, *stack_b);
	set_cheapest(*stack_b);
	execute_cheapest_move(stack_a, stack_b);
	reset_cheapest(*stack_b);
}

void	turk_algorithm(t_node **stack_a, t_node **stack_b)
{
	int	n;

	if (!stack_a || !*stack_a)
		return ;
	n = stack_size(*stack_a);
	if (n <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (is_sorted(*stack_a))
		return ;
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		process_b_cycle(stack_a, stack_b);
	final_rotation(stack_a);
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (!parse_and_build(argc, argv, &head_a))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (!head_a || !head_a->next || is_sorted(head_a))
	{
		free_list(head_a);
		return (0);
	}
	turk_algorithm(&head_a, &head_b);
	free_list(head_a);
	free_list(head_b);
	return (0);
}
