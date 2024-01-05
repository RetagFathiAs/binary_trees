#include "binary_trees.h"
/**
 * bst_insert - insert a node
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
/**
 * avl_insert - insert node
 * @tree: pointer to node
 * @value: value of node
 * Return: node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int factor_balance = 0;
	avl_t *node, *tmp;

	if (tree == NULL)
		return (NULL);

	node = bst_insert(tree, value);
	tmp = node;
	if (!node)
		return (NULL);
	while (node)
	{
		factor_balance = binary_tree_balance(node);
		if (factor_balance > 1 && tmp->n < node->left->n)
		{
			node = binary_tree_rotate_right(node);
		}
		if (factor_balance > 1 && tmp->n > node->left->n)
		{
			node = binary_tree_rotate_left(node->left);
			node = binary_tree_rotate_right(tmp->parent);
		}
		if (factor_balance < -1 && tmp->n < node->right->n)
		{
			node = binary_tree_rotate_right(node->right);
			node = binary_tree_rotate_left(tmp->parent);
		}
		if (factor_balance < -1 && tmp->n > node->right->n)
		{
			node = binary_tree_rotate_left(node);
		}
		node = node->parent;
	}
	return (tmp);
}
