/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:44:22 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 18:52:01 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nodes(t_node **head)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *head;
	while (temp != NULL)
	{
		ft_printf("Node[%i]: %d\n", i++, temp->data);
		temp = temp->next;
	}
}

t_node	*createnode(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	insert_front(t_node **head, int data)
{
	t_node	*new_node;

	new_node = createnode(data);
	if (!new_node)
		return ;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	new_node->next = *head;
	*head = new_node;
}

void	insert_end(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = createnode(data);
	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
