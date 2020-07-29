#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer
 * @number: value
 * Return: node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *temp, *new;
    
    if (!head){
        return NULL;
    }
    new = malloc(sizeof(listint_t));
    new->n = number;
    new->next = NULL;
    if (!*head)
    {
        *head = new;
        return *head;
    }
    else
    {
        temp = *head;
        if (temp->n > new->n){
            new->next = temp;
            *head = new;
            return *head;
        }
        else
        {
            while ((temp->next->n < new->n))
            {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;
            return new;
        }
    }
}
