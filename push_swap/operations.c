/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:04:34 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 20:08:41 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_silent(t_node **head)
{
	t_node	*last;
	t_node	*temp;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	temp = (*head)->next;
	while (last->next)
		last = last->next;
	last->next = *head;
	temp->prev = NULL;
	(*head)->prev = last;
	(*head)->next = NULL;
	*head = temp;
}

void	rev_rotate_silent(t_node **head)
{
	t_node	*last;
	t_node	*temp;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	temp = last->prev;
	temp->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}

// ra (rotate a)

void	ra(t_node **head_a)
{
	rotate_silent(head_a);
	ft_printf("ra\n");
}

// rb (rotate b)

void	rb(t_node **head_b)
{
	rotate_silent(head_b);
	ft_printf("rb\n");
}

// rr (ra && rb at same time)

void	rr(t_node **head_a, t_node **head_b)
{
	rotate_silent(head_a);
	rotate_silent(head_b);
	ft_printf("rr\n");
}
