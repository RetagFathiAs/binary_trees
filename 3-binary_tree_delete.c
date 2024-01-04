#include "binary_trees.h"

/**
 * binary_tree_delete - delete an entire tree.
 * @tree: pointer to parent node
 *
 * Return: no return
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
