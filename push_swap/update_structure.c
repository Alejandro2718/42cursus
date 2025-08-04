/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:37:22 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/04 20:05:03 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	set_above_median(t_node *stack)
{
	int	size;
	int	median;

	size = stack_size(stack);
	median = size / 2;
	while (stack)
	{
		if (stack->index > median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
}

void	reset_cheapest(t_node *stack)
{
	while (stack)
	{
		stack->cheapest = 0;
		stack = stack->next;
	}
}
