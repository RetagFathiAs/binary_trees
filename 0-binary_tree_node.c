#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: parent node
 * @value: integer to value
 * Return: pointer to node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = calloc(1, sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;

	return (node);
}
