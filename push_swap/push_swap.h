/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:21:02 by alejjime          #+#    #+#             */
/*   Updated: 2025/07/08 18:26:38 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*prev;
	struct node	*next;
}				t_node;

t_node			*createNode(int data);
void			insert_front(t_node **head, int data);
void			insert_end(t_node **head, int data);
void			free_list(t_node *head);
int				check_arg(char *argv);
void			print_nodes(t_node **head);
int				int_duplicate(char **argv);
void			sa(t_node **head_a);
void			sb(t_node **head_b);
void			ss(t_node **head_a, t_node **head_b);