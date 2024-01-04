#include "binary_trees.h"

/**
 * *binary_tree_insert_right - insert a node.
 * @parent: pointer to parent node
 * @value: value of the node
 * Return: a pointer to the created node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

	binary_tree_t *node = NULL, *temp = NULL;

	if (!parent)
		return (NULL);
	if (!parent->right)
	{
		node = binary_tree_node(parent, value);
		if (!node)
			return (NULL);
		parent->right = node;
		node->parent = parent;
	}
	else
	{
		node = binary_tree_node(parent, value);
		if (!node)
			return (NULL);
		temp = parent->right;
		parent->right = node;
		node->parent = parent;
		node->right = temp;
		temp->parent = node;
	}
	return (node);
}
