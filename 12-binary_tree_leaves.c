#include "binary_trees.h"

/**
 * binary_tree_is_leaf -  a function.
 *@node: ptr.
 * Return: 0 or 1.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 *@tree: ptr.
 * Return: 0 or .
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_is_leaf(tree) +
			binary_tree_leaves(tree->right) +
			binary_tree_leaves(tree->left));

}
