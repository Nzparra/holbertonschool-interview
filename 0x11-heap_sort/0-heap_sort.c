#include "sort.h"
/**
 * swap_array - change position between 2 array
 * @array: array
 * @first: position
 * @last: position
 * @size: size
 */
void swap_array(int *array,  int first, int last, size_t size)
{
	int aux, value;

	value = array[first];
	aux = array[last];
	array[last] = value;
	array[first] = aux;
	print_array(array, size);
}

/**
 * heap - find bigger in a heap
 * @array: array
 * @size_1: max index
 * @size_2: size
 * @i: i
 */
void heap(int *array, size_t size_1, size_t i, size_t size_2)
{
	size_t max, left, right;

	max = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < size_1 && array[left] > array[max])
		max = left;

	if (right < size_1 && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap_array(array, i, max, size_2);

		heap(array, size_1, max, size_2);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm.
 * @array: array of integers
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size == 1)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_array(array, 0, i, size);
		heap(array, i, 0, size);
	}
}
