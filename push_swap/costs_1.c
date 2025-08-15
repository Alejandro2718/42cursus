/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:06:08 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 17:26:34 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_node *stack)
{
	t_node	*cheapest;

	if (!stack)
		return ;
	cheapest = NULL;
	while (stack)
	{
		stack->cheapest = 0;
		if (!cheapest || stack->push_cost < cheapest->push_cost)
			cheapest = stack;
		stack = stack->next;
	}
	if (cheapest)
		cheapest->cheapest = 1;
}

void	calculate_push_costs(t_node *stack_a, t_node *stack_b)
{
	int		len_a;
	int		len_b;
	t_node	*cur;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	cur = stack_b;
	set_target_nodes(stack_a, stack_b);
	while (cur)
	{
		cur->push_cost = calculate_simultaneous_cost(cur, len_a, len_b);
		cur = cur->next;
	}
}
