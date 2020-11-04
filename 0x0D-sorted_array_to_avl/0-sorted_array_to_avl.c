#include "binary_trees.h"
/**
 * atree - logic to construct a avl tree from a sorted array
 * @array: array to turns into avl tree
 * @begin: first index of the array
 * @last: last index of the array
 * Return: NULL or the new node
 */
avl_t *a_tree(int *array, int begin, int last)
{
	avl_t *node, *left, *right;
	int mid;

	if (begin > last)
		return (NULL);
	mid = (last + begin) / 2;
	left = a_tree(array, begin, mid - 1);
	right = a_tree(array, mid + 1, last);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = array[mid];
	node->parent = NULL;
	node->left = left;
	node->right = right;

	if (left != NULL)
		left->parent = node;
	if (right != NULL)
		right->parent = node;
	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);
	return (a_tree(array, 0, (int)(size - 1)));
}
