#include "push_swap.h"

//sa (swap a)

void sa(t_node **head_a)
{
    t_node *temp;
    int i;

    i = 0;
    temp = (*head_a)->next;
    i = (*head_a)->data;
    (*head_a)->data = temp->data;
    temp->data = i;

    ft_printf("sa\n");

}

//sb (swap b)

void sb(t_node **head_b)
{
    t_node *temp;
    int i;

    i = 0;
    temp = (*head_b)->next;
    i = (*head_b)->data;
    (*head_b)->data = temp->data;
    temp->data = i;

    ft_printf("sb\n");

}

//ss (sa and sb at the same time)

void ss(t_node **head_a, t_node **head_b)
{
    sa(head_a);
    sb(head_b);

    ft_printf("ss\n");
}

//pa (push a)

void pa(t_node **head_a, t_node **head_b)
{
    
}