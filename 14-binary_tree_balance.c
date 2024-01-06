#include "binary_trees.h"

/**
* binary_tree_height - Compute the height of a binary tree.
* @tree: Pointer to the root node of the tree.
* Return: Height of the tree, or 0 if tree is NULL.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
* binary_tree_balance - Measure the balance factor of a binary tree.
* @tree: Pointer to the root node of the tree.
* Return: Balance factor of the tree, or 0 if tree is NULL.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
		return (0);
	if (tree->left)
		h_left = 1 + binary_tree_height(tree->left);
	if (tree->right)
		h_right = 1 + binary_tree_height(tree->right);
	return (h_left - h_right);
}
