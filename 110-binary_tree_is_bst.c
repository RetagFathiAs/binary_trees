#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - function
 * @tree: node to check
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (isBST(tree, INT_MIN, INT_MAX))
		return (1);
	return (0);
}


/**
 * isBST - check
 * @tree: pointer to root node
 * @min: min
 * @max: max
 * Return: 1 or 0
 */

int isBST(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (isBST(tree->left, min, tree->n) &&
		isBST(tree->right, tree->n, max));

}
