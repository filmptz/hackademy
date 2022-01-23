#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    void *data;
    struct node *next;
} node_t;


node_t  *list_create(void *data){
    node_t *block = (node_t *)malloc(sizeof(node_t));
    block->data = data;
    block->next = NULL;

    return block;
}

void    list_destroy(node_t **head, void (*fp)(void *data)) 
{
    node_t *current = *head;
    while (current != NULL) 
    {
        node_t *block = current -> next;
        fp(current -> data);
        free(current);
        current = block; 
    }

    head = NULL;
}


void    list_push(node_t *head, void *data) 
{
    node_t *current = head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }

    current -> next = list_create(data);
}

void    list_unshift(node_t **head, void *data) 
{
    node_t *new_head = list_create(data);
    new_head -> next = *head;
    *head = new_head; 
}

void    *list_pop(node_t **head) 
{
    node_t *current = *head, *block = NULL;

    while (current -> next != NULL) 
    {
        block = current;
        current = current -> next;
    }

    void *data = current -> data;
    free(current);
    block -> next = NULL;

    return data;
}

void    *list_shift(node_t **head) 
{
    node_t *block = *head;
    node_t *new_head = block -> next;

    void *data = block -> data;
    free(block);

    *head = new_head;

    return data;
}


void *list_remove(node_t **head, int pos)
{
    if (pos == 0) 
    {
        return list_shift(head);
    }

    node_t *current = *head;
    node_t *block = NULL;

    for (int i = 1; i < pos - 1; ++i) 
    {

        if (current == NULL) 
        {
            return NULL;
        }
        block = current;
        current = current->next;
    }

    block -> next = current -> next;

    void *data = current -> data;
    free(current);

    return data;
}

void    list_print(node_t *head) 
{
    node_t *current = head;
    while (current != NULL) 
    {
        printf("%s", (char *) current -> data);
        current = current -> next;
    }
}

void    list_visitor(node_t *head, void (*fp)(void *data)) 
{
    node_t *current = head;
    while (current != NULL) 
    {
        fp(current -> data);
        current = current -> next;
    }
}
