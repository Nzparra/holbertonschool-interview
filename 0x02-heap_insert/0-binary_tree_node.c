#include "binary_trees.h"

/**
 * binary_tree_node - createsBinary tree node
 * @parent: Pointer to the parent node
 * @value: new node
 * Return: Pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *new;

	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;
	return (new);
}
