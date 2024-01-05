#include "binary_trees.h"
#include <limits.h>

/**
 * bst_remove - remove a node
 * @root: root of the tree
 * @value: value
 * Return: pointer
 */
bst_t *bst_remove(bst_t *root, int value)
{

	bst_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = minValue(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);

}

/**
 * minValue - minvalue to replace the root
 * @node: node to start checking
 * Return: pointer
 */
bst_t *minValue(bst_t *node)
{
	bst_t *current;

	current = node;
	while (current && current->left != NULL)
		current = current->left;

	return (current);
}
