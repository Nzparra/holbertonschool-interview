#include "sort.h"
/**
 * bigNum - gets the biggest number
 * @array: array to search
 * @size: size of the array
 * Return: biggest num in array
 */
int bigNum(int *array, size_t size)
{
	size_t i;
	int max;

	max = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * SortLogic - Sort the array
 * @array: the array to sort
 * @size: size of the array
 * @exp: digit to count around
 */
void SortLogic(int *array, int size, int exp)
{
	int *output, i;
	int auxArray[10] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < size; i++)
		auxArray[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		auxArray[i] += auxArray[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[auxArray[(array[i] / exp) % 10] - 1] = array[i];
		auxArray[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - LDS Method radix sort
 * @array: the array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int maxNum, exp;

	if (size < 2)
		return;

	maxNum = bigNum(array, size);
	for (exp = 1; maxNum / exp > 0; exp *= 10)
	{
		SortLogic(array, size, exp);
		print_array(array, size);
	}
}
