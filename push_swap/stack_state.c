/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:05:35 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 15:32:06 by alejjime         ###   ########.fr       */
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

int	find_median_value(t_node *head)
{
	t_node	*temp;
	int		*values;
	int		size;
	int		i;
	int		j;
	int		median;
	int		swap;

	if (!head)
		return (0);
	size = stack_size(head);
	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		return (0);
	temp = head;
	i = 0;
	while (temp)
	{
		values[i++] = temp->data;
		temp = temp->next;
	}
	// Simple bubble sort to find median
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				swap = values[j];
				values[j] = values[j + 1];
				values[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
	median = values[size / 2];
	free(values);
	return (median);
}

// void	print_nodes(t_node **head)
// {
// 	t_node	*temp;
// 	int		i;

// 	i = 0;
// 	temp = *head;
// 	if (!temp)
// 	{
// 		ft_printf("Pila vacía\n");
// 		return ;
// 	}
// 	while (temp != NULL)
// 	{
// 		ft_printf("Node[%i]: %d\n", i++, temp->data);
// 		temp = temp->next;
// 	}
// }
