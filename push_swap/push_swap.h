/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:21:02 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 21:08:09 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	int			data;
	int			index;
	int			push_cost;
	int			above_median;
	int			cheapest;
	struct node	*target_node;
	struct node	*prev;
	struct node	*next;
}				t_node;

// list utils
t_node			*createnode(int data);
void			insert_front(t_node **head, int data);
void			insert_end(t_node **head, int data);
void			free_list(t_node *head);
void			print_nodes(t_node **head);

// args/validation
int				check_arg(char *argv);
int				int_duplicate(char **argv);
int				parse_and_build(int argc, char **argv, t_node **head_a);

// ops
void			sa(t_node **head_a);
void			sb(t_node **head_b);
void			ss(t_node **head_a, t_node **head_b);
void			pa(t_node **head_a, t_node **head_b);
void			pb(t_node **head_a, t_node **head_b);
void			ra(t_node **head_a);
void			rb(t_node **head_b);
void			rr(t_node **head_a, t_node **head_b);
void			rra(t_node **head_a);
void			rrb(t_node **head_b);
void			rrr(t_node **head_a, t_node **head_b);
void			rotate_silent(t_node **head);
void			rev_rotate_silent(t_node **head);

// state/helpers
int				stack_size(t_node *head);
int				find_position(t_node *head, int value);
int				is_sorted(t_node *head);
int				find_min(t_node *head);
int				find_max(t_node *head);
void			update_index(t_node *stack);
void			set_above_median(t_node *stack);
void			reset_cheapest(t_node *stack);

// algorithm
void			move_to_top(t_node **stack, t_node *target);
void			execute_cheapest_move(t_node **stack_a, t_node **stack_b);
void			push_all_but_three(t_node **stack_a, t_node **stack_b);
void			sort_three(t_node **stack_a);
void			final_rotation(t_node **stack_a);
void			turk_algorithm(t_node **stack_a, t_node **stack_b);
void			calculate_push_costs(t_node *stack_a, t_node *stack_b);
void			set_cheapest(t_node *stack);
void			rotate_both_down(t_node **a, t_node **b, t_node *ta,
					t_node *nb);
void			align_a(t_node **a, t_node *ta);
void			align_b(t_node **b, t_node *nb);

#endif