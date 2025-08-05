/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:06:36 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/05 18:42:37 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_nodes(t_node *stack_a, t_node *stack_b)
{
	t_node	*head;
	t_node	*best;
	int		min;

	head = stack_a;
	best = NULL;
	min = find_min(stack_a);
	if (min > stack_b->data)
		best = while (stack_b)
		{
			stack_a = head;
			while (stack_a)
			{
				if (stack_a->data > stack_b->data)
					stack_b->target_node = stack_a;
				stack_a = stack_a->next;
			}
			stack_b = stack_b->next;
		}
}

void	calculate_push_costs(t_node *stack_a, t_node *stack_b)
{
}

void	set_cheapest(t_node *stack)
{
}
