#include "binary_trees.h"
#include <limits.h>

/**
 * bst_insert - insert
 * @tree: root
 * @value: value of the node
 * Return: pointer to the node
 */
bst_t *bst_insert(bst_t **tree, int value)
{

	bst_t *new = NULL, *x;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		if (*tree)
			(*tree)->parent = NULL;
		return (*tree); }
	x = *tree;
	while (1)
	{
		if (value < x->n)
		{
			if (!x->left)
			{
				new = binary_tree_node(*tree, value);
				new->parent = x;
				return (x->left = new);
			}
			x = x->left;
		}
		else
		{
			if (!x->right)
			{
				new = binary_tree_node(*tree, value);
				new->parent = x;
				return (x->right = new);
			}
			x = x->right;
		}
		if (value == x->n)
		{
			free(new);
			return (NULL);
		}
	}
}
