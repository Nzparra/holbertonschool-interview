#include "search_algos.h"
/**
 * binary_search - recursion to divide in two mids
 * @array: array
 * @begin: 1 index
 * @last:  index
 * @value: search
 * Return: index or -1 if not found
 */
int binary_search(int *array, int begin, int last, int value)
{
	int mid, i;

	printf("Searching in array: ");
	for (i = begin; i < last; i++)
		printf("%i, ", array[i]);
	printf("%i\n", array[i]);
	mid = ((last - begin) / 2) + begin;
	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	if (begin == last)
		return (-1);
	if (array[mid] >= value)
		return (binary_search(array, begin, mid, value));
	if (array[mid] < value)
		return (binary_search(array, mid + 1, last, value));
	return (-1);
}
/**
 * advanced_binary - searches a specific value
 * @array: array to search in
 * @size: size
 * @value: search
 * Return: index or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (binary_search(array, 0, (int)(size - 1), value));
}
