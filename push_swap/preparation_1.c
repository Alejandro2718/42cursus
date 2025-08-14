/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:24:45 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 20:25:05 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotation(t_node **stack_a)
{
	t_node	*min_node;
	int		min_val;

	if (!stack_a || !*stack_a)
		return ;
	update_index(*stack_a);
	set_above_median(*stack_a);
	min_val = find_min(*stack_a);
	min_node = *stack_a;
	while (min_node && min_node->data != min_val)
		min_node = min_node->next;
	if (!min_node)
		return ;
	move_to_top(stack_a, min_node);
}
