#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures
 * the depth of a node in a binary tree.
 *@tree: ptr.
 * Return: 0 or 1.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
