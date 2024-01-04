#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through pre-order traversal
 * @tree: pointer to root
 * @func: function to print
 * return: no return
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);

}
