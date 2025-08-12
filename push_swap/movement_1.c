/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:46:12 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 19:50:56 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_down(t_node **a, t_node **b, t_node *ta, t_node *nb)
{
	while (nb->index != 0 && ta->index != 0 && nb->above_median == 0
		&& ta->above_median == 0)
	{
		rrr(a, b);
		update_index(*a);
		update_index(*b);
	}
}

void	align_a(t_node **a, t_node *ta)
{
	while (ta->index != 0)
	{
		if (ta->above_median == 1)
			ra(a);
		else
			rra(a);
		update_index(*a);
	}
}

void	align_b(t_node **b, t_node *nb)
{
	while (nb->index != 0)
	{
		if (nb->above_median == 1)
			rb(b);
		else
			rrb(b);
		update_index(*b);
	}
}
