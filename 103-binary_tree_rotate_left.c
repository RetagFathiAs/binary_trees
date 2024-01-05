#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs
 * a left-rotation on a binary tree.
 * @tree: ptr.
 * Return: NULL or.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *tmp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		tmp = tree->right->left;
		x = tree->right;
		x->parent = tree->parent;
		x->left = tree;
		tree->parent = x;
		tree->right = tmp;
		if (tmp)
			tmp->parent = tree;
		return (x);
	}
	return (NULL);
}
