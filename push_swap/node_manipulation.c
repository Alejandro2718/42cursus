#include "push_swap.h"

t_node *createNode(int data)
{
	t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_front(t_node** head, int data)
{
    t_node *new_node = createNode(data);
    if (!new_node)
        return ;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    new_node->next = *head;
    *head = new_node;
}

void insert_end(t_node** head, int data)
{
    t_node *new_node = createNode(data);
    if (!new_node) 
        return ;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    t_node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}

void free_list(t_node *head)
{
    t_node *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}