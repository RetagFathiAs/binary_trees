#include "binary_trees.h"

/**
 * binary_tree_is_root - function that checks if a node is root
 * @node: node to  check
 * Return: 1 if is root or 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->parent == NULL)
		return (1);
	return (0);
}
