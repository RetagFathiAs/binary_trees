#include "binary_trees.h"
/**
 * binary_tree_size - function that
 * @tree: pointer
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	count = binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right);
	return (count);
}
/**
 * is_complete - check
 * @root: node
 * @index: index
 * @size: size
 * Return: 1 or 0
 */
int is_complete(binary_tree_t *root, size_t index, size_t size)
{
	if (root == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(root->left, 2 * index + 1, size) &&
			is_complete(root->right, 2 * index + 2, size));

}
/**
 * binary_tree_is_complete - function
 * @tree: node to check
 * Return: 1 or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index = 0;

	if (!tree)
		return (0);

	size = binary_tree_size((binary_tree_t *)tree);
	if (is_complete((binary_tree_t *)tree, index, size))
		return (1);
	return (0);
}
