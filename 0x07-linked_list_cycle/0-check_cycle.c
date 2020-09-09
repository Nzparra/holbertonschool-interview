#include "lists.h"
/**
 * check_cycle - find a loop in a linked list
 * @list: The linked list
 * Return: 1 loop or 0 for not
**/
int check_cycle(listint_t *list)
{
	listint_t *first, *second;

	if (list == NULL)
		return (0);
	first = second = list;
	while (first && first->next && first->next->next)
	{
		second = second->next;
		first = first->next->next;
		if (first == second)
		{
			return (1);
		}
	}
	return (0);
}
