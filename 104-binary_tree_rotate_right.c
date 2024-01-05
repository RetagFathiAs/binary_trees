#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs
 * a right-rotation on a binary tree.
 * @tree: ptr.
 * Return: NULL or .
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *tmp;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		tmp = tree->left->right;
		x = tree->left;
		x->parent = tree->parent;
		x->right = tree;
		tree->parent = x;
		tree->left = tmp;
		if (tmp)
			tmp->parent = tree;
		return (x);
	}
	return (NULL);
}
