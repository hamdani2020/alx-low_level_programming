#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a singly linked list
 * @head: a double pointer to the head of the list
 *
 * Return: the value of the deleted node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
    if (head == NULL || *head == NULL) {
        return 0;
    }
    
    listint_t *temp = *head;  // save the current head node
    int value = temp->n;      // save its value for return later
    *head = temp->next;       // update the head pointer to the next node
    free(temp);               // free the memory of the deleted node
    
    return value;
}

