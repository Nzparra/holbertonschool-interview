#include "search.h"
/**
 * search_index - goes through the linked list
 * @prev: prev
 * @actual: actual
 * @value: value
 * Return: value*/
skiplist_t *search_index(skiplist_t *prev, skiplist_t *actual, int value)
{
	while (prev && prev->index <= actual->index)
	{
		printf("Value checked at index [%lu] = [%i]\n", prev->index,
		       prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
/**
 * linear_skip - jump search algorithm with linked list
 * @list: list to search the value
 * @value: value to search
 * Return: Node where the value is or NULL if the value couldn't be find
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *actual, *prev;
	size_t act_i, pre_i;

	if (!list)
		return (NULL);
	actual = list;
	while (actual->express != NULL)
	{
		prev = actual;
		actual = actual->express;
		act_i = actual->index;
		pre_i = prev->index;
		printf("Value checked at index [%lu] = [%i]\n", act_i,
		       actual->n);
		if (prev->n > value && prev->index == 0)
			return (NULL);
		if (actual->n >= value)
			break;
	}
	if (!actual->express && actual->n < value)
	{
		prev = actual;
		pre_i = prev->index;
		while (actual->next)
			actual = actual->next;
		act_i = actual->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", pre_i, act_i);
	return (search_index(prev, actual, value));
}
