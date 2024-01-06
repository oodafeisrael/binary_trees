#include "binary_trees.h"

/**
* binary_tree_height - Compute the height of a binary tree.
* @tree: Pointer to the root node of the tree.
* Return: Height of the tree, or 0 if tree is NULL.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height) ? left_height +
			1 : right_height + 1);
}

/**
* binary_tree_balance - Measure the balance factor of a binary tree.
* @tree: Pointer to the root node of the tree.
* Return: Balance factor of the tree, or 0 if tree is NULL.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((int)(left_height - right_height));
}
