/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_state_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:30:33 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 17:31:06 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_values_to_array(t_node *head, int size)
{
	t_node	*temp;
	int		*values;
	int		i;

	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	temp = head;
	i = 0;
	while (temp)
	{
		values[i++] = temp->data;
		temp = temp->next;
	}
	return (values);
}

static void	bubble_sort_array(int *values, int size)
{
	int	i;
	int	j;
	int	swap;

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
}

int	find_median_value(t_node *head)
{
	int	*values;
	int	size;
	int	median;

	if (!head)
		return (0);
	size = stack_size(head);
	values = copy_values_to_array(head, size);
	if (!values)
		return (0);
	bubble_sort_array(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}
