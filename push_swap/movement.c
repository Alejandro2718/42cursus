#include "push_swap.h"

t_node *get_cheapest(t_node *stack)                // Obtener nodo con cheapest = 1
{
    while(stack)
    {
        if (stack->cheapest == 1)
            return (stack);
        stack = stack->next;
    }
    return NULL;
}

void move_to_top(t_node **stack, t_node *target)   // Rotar hasta traer target arriba
{
    if (!stack || !*stack || !target)
        return;

    while(target->index != 0)
    {
        if (target->above_median == 1)
        {
            ra(stack);
        }
        else
            rra(stack);
        update_index(*stack);
    }   
}

static void rotate_both_up(t_node **a, t_node **b, t_node *ta, t_node *nb)
{
    while (nb->index != 0 && ta->index != 0 && nb->above_median == 1 && ta->above_median == 1)
    {
        rr(a, b);
        update_index(*a);
        update_index(*b);
    }
}

static void rotate_both_down(t_node **a, t_node **b, t_node *ta, t_node *nb)
{
    while (nb->index != 0 && ta->index != 0 && nb->above_median == 0 && ta->above_median == 0)
    {
        rrr(a, b);
        update_index(*a);
        update_index(*b);
    }
}

static void align_a(t_node **a, t_node *ta)
{
    while (ta->index != 0)
    {
        if (ta->above_median == 1) ra(a);
        else rra(a);
        update_index(*a);
    }
}

static void align_b(t_node **b, t_node *nb)
{
    while (nb->index != 0)
    {
        if (nb->above_median == 1) rb(b);
        else rrb(b);
        update_index(*b);
    }
}

static void push_b_to_a_and_update(t_node **a, t_node **b)
{
    pa(a, b);
    update_index(*a);
    if (*b) update_index(*b);
}

void execute_cheapest_move(t_node **stack_a, t_node **stack_b)
{
    t_node *node_b;
    t_node *target_a;

    if (!stack_a || !stack_b || !*stack_b)
        return;
    node_b = get_cheapest(*stack_b);
    if (!node_b || !(target_a = node_b->target_node))
        return;
    rotate_both_up(stack_a, stack_b, target_a, node_b);
    rotate_both_down(stack_a, stack_b, target_a, node_b);
    align_a(stack_a, target_a);
    align_b(stack_b, node_b);
    push_b_to_a_and_update(stack_a, stack_b);
}