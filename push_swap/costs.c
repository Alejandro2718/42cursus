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

static t_node *find_min_node(t_node *a)
{
	t_node *min;
    t_node *cur;

    if (!a) 
		return NULL;
    min = a;
	cur = a->next;
    while (cur) {
        if (cur->value < min->value)
            min = cur;
        cur = cur->next;
    }
    return min;
}

void	calculate_push_costs(t_node *stack_a, t_node *stack_b)
{
	int		len_a;
	int		len_b;
	t_node	*cur;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	cur = stack_b;
	while (cur)
	{
		if (cur->pos <= len_b / 2)
			cur->cost_b = cur->pos;
		else
			cur->cost_b = cur->pos - len_b;
		if (cur->target_pos <= len_a / 2)
			cur->cost_a = cur->target_pos;
		else
			cur->cost_a = cur->target_pos - len_a;
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
