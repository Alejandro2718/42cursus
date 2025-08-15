/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:05:35 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 17:30:48 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Contar elementos en una pila
int	stack_size(t_node *head)
{
	t_node	*temp;
	int		i;

	temp = head;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// Encontrar la posición de un elemento (0 = arriba)
int	find_position(t_node *head, int value)
{
	t_node	*temp;
	int		i;

	temp = head;
	i = 0;
	if (head == NULL)
		return (-1);
	while (temp != NULL)
	{
		if (temp->data == value)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}

// Verificar si una pila está ordenada
int	is_sorted(t_node *head)
{
	t_node	*temp;

	if (head == NULL || head->next == NULL)
		return (1);
	temp = head;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

// Encontrar el valor mínimo/máximo
int	find_min(t_node *head)
{
	t_node	*temp;
	int		menor;

	if (head == NULL)
		return (0);
	temp = head;
	menor = head->data;
	while (temp != NULL)
	{
		if (menor > temp->data)
			menor = temp->data;
		temp = temp->next;
	}
	return (menor);
}

int	find_max(t_node *head)
{
	t_node	*temp;
	int		mayor;

	if (head == NULL)
		return (0);
	temp = head;
	mayor = head->data;
	while (temp != NULL)
	{
		if (mayor < temp->data)
			mayor = temp->data;
		temp = temp->next;
	}
	return (mayor);
}
