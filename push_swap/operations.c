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
    t_node *temp_a, *temp_b;
    int i, j;

    i = 0;
    temp_a = (*head_a)->next;
    i = (*head_a)->data;
    (*head_a)->data = temp_a->data;
    temp_a->data = i;

    j = 0;
    temp_b = (*head_b)->next;
    j = (*head_b)->data;
    (*head_b)->data = temp_b->data;
    temp_b->data = j;

    ft_printf("ss\n");
}

//pa (push a)

void pa(t_node **head_a, t_node **head_b)
{
    t_node *temp;

    if (*head_b == NULL)
        return ;
    temp = (*head_b);
    (*head_b) = (*head_b)->next;
    if (*head_b)
        (*head_b)->prev = NULL;
    temp->prev = NULL;
    if (*head_a != NULL)
    {
       
        temp->next = (*head_a);
        (*head_a)->prev = temp;
    }
    else
        temp->next = NULL;
    (*head_a) = temp; 
    ft_printf("pa\n");
}

//pb (push b)

void pb(t_node **head_a, t_node **head_b)
{
    t_node *temp;

    if (*head_a == NULL)
        return ;
    temp = (*head_a);
    (*head_a) = (*head_a)->next;
    if (*head_a)
        (*head_a)->prev = NULL;
    temp->prev = NULL;
    if (*head_b != NULL)
    {
       
        temp->next = (*head_b);
        (*head_b)->prev = temp;
    }
    else
        temp->next = NULL;
    (*head_b) = temp; 
    ft_printf("pb\n");
}

//ra (rotate a)

void ra(t_node **head_a)
{
    t_node *last;
    t_node *temp;

    if (*head_a == NULL || (*head_a)->next == NULL)
        return ;
    last = (*head_a);
    temp = (*head_a)->next;
    while (last->next)
        last = last->next;
    last->next = (*head_a);

    temp->prev = NULL;

    (*head_a)->prev = last;
    (*head_a)->next = NULL;
    
    (*head_a) = temp;
    ft_printf("ra\n");
}

//rb (rotate b)

void rb(t_node **head_b)
{
    t_node *last;
    t_node *temp;

    if (*head_b == NULL || (*head_b)->next == NULL)
        return ;
    last = (*head_b);
    temp = (*head_b)->next;
    while (last->next)
        last = last->next;
    last->next = (*head_b);
    temp->prev = NULL;
    (*head_b)->prev = last;
    (*head_b)->next = NULL;
    (*head_b) = temp;
    ft_printf("rb\n");
}

//rr (ra && rb at same time)

