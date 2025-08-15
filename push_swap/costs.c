/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:06:36 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 17:26:35 by alejjime         ###   ########.fr       */
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

static int	calculate_rotation_cost(int index, int stack_size)
{
	if (index <= stack_size / 2)
		return (index);
	else
		return (stack_size - index);
}

static int	can_rotate_simultaneously(t_node *node_b, int len_a, int len_b)
{
	if (!node_b->target_node)
		return (0);
	return ((node_b->index <= len_b / 2 && node_b->target_node->index <= len_a
			/ 2) || (node_b->index > len_b / 2
			&& node_b->target_node->index > len_a / 2));
}

int	calculate_simultaneous_cost(t_node *node_b, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;
	int	simultaneous_cost;

	cost_b = calculate_rotation_cost(node_b->index, len_b);
	if (node_b->target_node)
		cost_a = calculate_rotation_cost(node_b->target_node->index, len_a);
	else
		cost_a = 0;
	simultaneous_cost = cost_a + cost_b;
	if (can_rotate_simultaneously(node_b, len_a, len_b))
	{
		if (cost_a > cost_b)
			simultaneous_cost = cost_a;
		else
			simultaneous_cost = cost_b;
	}
	return (simultaneous_cost);
}
