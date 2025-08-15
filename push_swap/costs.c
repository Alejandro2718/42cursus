/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:06:36 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 15:54:48 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min_node(t_node *a)
{
	t_node	*min;
	t_node	*cur;

	if (!a)
		return (NULL);
	min = a;
	cur = a->next;
	while (cur)
	{
		if (cur->data < min->data)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

void	set_target_nodes(t_node *stack_a, t_node *stack_b)
{
	t_node	*cur_b;
	t_node	*cur_a;
	t_node	*best;

	cur_b = stack_b;
	while (cur_b)
	{
		best = NULL;
		cur_a = stack_a;
		while (cur_a)
		{
			if (cur_a->data > cur_b->data)
			{
				if (!best || cur_a->data < best->data)
					best = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (!best)
			best = find_min_node(stack_a);
		cur_b->target_node = best;
		cur_b = cur_b->next;
	}
}

void	calculate_push_costs(t_node *stack_a, t_node *stack_b)
{
	int		len_a;
	int		len_b;
	t_node	*cur;
	int		cost_b;
	int		cost_a;
	int		simultaneous_cost;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	cur = stack_b;
	set_target_nodes(stack_a, stack_b);
	while (cur)
	{
		if (cur->index <= len_b / 2)
			cost_b = cur->index;
		else
			cost_b = len_b - cur->index;
		if (cur->target_node && cur->target_node->index <= len_a / 2)
			cost_a = cur->target_node->index;
		else if (cur->target_node)
			cost_a = len_a - cur->target_node->index;
		else
			cost_a = 0;
		simultaneous_cost = cost_a + cost_b;
		if (cur->target_node)
		{
			if ((cur->index <= len_b / 2 && cur->target_node->index <= len_a
					/ 2) || (cur->index > len_b / 2
					&& cur->target_node->index > len_a / 2))
			{
				if (cost_a > cost_b)
					simultaneous_cost = cost_a;
				else
					simultaneous_cost = cost_b;
			}
		}
		cur->push_cost = simultaneous_cost;
		cur = cur->next;
	}
}

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
