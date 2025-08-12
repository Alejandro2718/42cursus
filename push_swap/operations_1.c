/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:56:28 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 20:09:17 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a)

void	sa(t_node **head_a)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = (*head_a)->next;
	i = (*head_a)->data;
	(*head_a)->data = temp->data;
	temp->data = i;
	ft_printf("sa\n");
}

// sb (swap b)

void	sb(t_node **head_b)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = (*head_b)->next;
	i = (*head_b)->data;
	(*head_b)->data = temp->data;
	temp->data = i;
	ft_printf("sb\n");
}

// ss (sa and sb at the same time)

void	ss(t_node **head_a, t_node **head_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		i;
	int		j;

	i = 0;
	temp_a = (*head_a)->next;
	i = (*head_a)->data;
	(*head_a)->data = temp_a->data;
	temp_a->data = i;
	j = 0;
	temp_b = (*head_b)->next;
	j = (*head_b)->data;
	(*head_b)->data = temp_b->data;
	temp_b->data = j;
	ft_printf("ss\n");
}

// pa (push a)

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*temp;

	if (*head_b == NULL)
		return ;
	temp = (*head_b);
	(*head_b) = (*head_b)->next;
	if (*head_b)
		(*head_b)->prev = NULL;
	temp->prev = NULL;
	if (*head_a != NULL)
	{
		temp->next = (*head_a);
		(*head_a)->prev = temp;
	}
	else
		temp->next = NULL;
	(*head_a) = temp;
	ft_printf("pa\n");
}

// pb (push b)

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*temp;

	if (*head_a == NULL)
		return ;
	temp = (*head_a);
	(*head_a) = (*head_a)->next;
	if (*head_a)
		(*head_a)->prev = NULL;
	temp->prev = NULL;
	if (*head_b != NULL)
	{
		temp->next = (*head_b);
		(*head_b)->prev = temp;
	}
	else
		temp->next = NULL;
	(*head_b) = temp;
	ft_printf("pb\n");
}
