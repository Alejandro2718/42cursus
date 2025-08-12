/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:09:09 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 20:09:25 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a)

void	rra(t_node **head_a)
{
	rev_rotate_silent(head_a);
	ft_printf("rra\n");
}

// rrb (reverse rotate b)

void	rrb(t_node **head_b)
{
	rev_rotate_silent(head_b);
	ft_printf("rrb\n");
}

// rrr (rra and rrb at the same time)

void	rrr(t_node **head_a, t_node **head_b)
{
	rev_rotate_silent(head_a);
	rev_rotate_silent(head_b);
	ft_printf("rrr\n");
}
