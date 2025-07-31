





#include "push_swap.h"

// Contar elementos en una pila
int stack_size(t_node *head)
{
    t_node *temp;
    int i;

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
int find_position(t_node *head, int value)
{
    t_node *temp;
    int i;

    temp = head;
    i = 0;
    if (head != NULL)
        return (-1);
    while (temp != NULL)
    {
        if (temp->data == value)
            return(i);
        temp = temp->next;
        i++;
    }
    return (-1);
}

// Verificar si una pila está ordenada
int is_sorted(t_node *head)
{
    t_node *temp;

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
int find_min(t_node *head);
{

}

int find_max(t_node *head);