#include "binary_trees.h"
/**
 * binary_tree_height - function
 * @tree: pointer to a tree
 * Return: size of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t count = 0, count2 = 0;

	if (!tree)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
	{
		count = binary_tree_height(tree->left) + 1;
		count2 = binary_tree_height(tree->right) + 1;
	}
	if (count > count2)
		return (count);

	return (count2);
}
/**
 * binary_tree_is_avl - function
 * @tree: node to check
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_height(tree->left) - binary_tree_height(tree->right))
		return (0);
	return (1);
}
