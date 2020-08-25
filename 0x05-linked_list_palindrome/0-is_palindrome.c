#include "lists.h"
/* *
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    int i, j;
    int numbers[1000000];
    listint_t *temp;

    if (*head == NULL)
    {
        return (1);
    }
    i = 0;
    temp = *head;
    while (temp != NULL)
    {
        numbers[i] = temp->n;
        temp = temp->next;
        i++;
    }
    i--;
    for (j = 0; j <= (i / 2); j++)
    {
        if (numbers[j] != numbers[i - j])
        {
            return (0);
        }
    }
    return (1);
}
