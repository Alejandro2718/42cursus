/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:53:11 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 15:55:09 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_top3_values(t_node *s, int *a, int *b, int *c)
{
	*a = s->data;
	*b = s->next->data;
	*c = s->next->next->data;
}

static int	three_case(int a, int b, int c)
{
	if (a < b && b < c)
		return (0);
	if (a > b && b < c && a < c)
		return (1);
	if (a > b && b > c)
		return (2);
	if (a > b && b < c && a > c)
		return (3);
	if (a < b && b > c && a < c)
		return (4);
	return (5);
}

static void	apply_three_case(t_node **stack_a, int code)
{
	if (code == 1)
		sa(stack_a);
	else if (code == 2)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (code == 3)
		ra(stack_a);
	else if (code == 4)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (code == 5)
		rra(stack_a);
}

void	push_all_but_three(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	pushed;

	if (!stack_a || !*stack_a)
		return ;
	len = stack_size(*stack_a);
	if (len <= 3)
		return ;
	pushed = 0;
	pb(stack_a, stack_b);
	pushed++;
	if (len > 4)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
	while (len - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;
	int	code;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!(*stack_a)->next->next)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
		return ;
	}
	get_top3_values(*stack_a, &a, &b, &c);
	code = three_case(a, b, c);
	apply_three_case(stack_a, code);
}
