#include "push_swap.h"

void push_all_but_three(t_node **stack_a, t_node **stack_b) // Mover a B excepto 3 menores
{
    t_node *min_node;
    int min_val;
    if (!stack_a || !*stack_a)
        return;
    while (stack_size(*stack_a) > 3)
    {
        update_index(*stack_a);
        set_above_median(*stack_a);
        min_val = find_min(*stack_a);
        min_node = *stack_a;
        while (min_node && min_node->data != min_val)
            min_node = min_node->next;
        if (!min_node)
            break;
        move_to_top(stack_a, min_node);
        pb(stack_a, stack_b);
        print_nodes(stack_a);
        print_nodes(stack_b);
    }
}
void sort_three(t_node **stack_a)                          // Ordenar los 3 elementos
{
    int a;
    int b;
    int c;
    if (!stack_a || !*stack_a)
        return;
    if (!(*stack_a)->next)
        return;
    if (!(*stack_a)->next->next)
    {
        if ((*stack_a)->data > (*stack_a)->next->data)
            sa(stack_a);
        return;
    }
    a = (*stack_a)->data;
    b = (*stack_a)->next->data;
    c = (*stack_a)->next->next->data;
    if (a < b && b < c)
        return;
    if (a > b && b < c && a < c)
    {
        sa(stack_a);
        return;
    }
    if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
        return;
    }
    if (a > b && b < c && a > c)
    {
        ra(stack_a);
        return;
    }
    if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
        return;
    }
    if (a < b && b > c && a > c)
        rra(stack_a);
}
void final_rotation(t_node **stack_a)                       // Rotar para poner min arriba
{
    t_node *min_node;
    int min_val;
    if (!stack_a || !*stack_a)
        return;
    min_val = find_min(*stack_a);
    min_node = *stack_a;
    while (min_node && min_node->data != min_val)
        min_node = min_node->next;
    if (!min_node)
        return;
    move_to_top(stack_a, min_node);
}