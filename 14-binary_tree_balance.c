#include "binary_trees.h"

/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: pointer to the root node of the tree to measure the
* balance factor
*
* Return: height
* If tree is NULL, return 0
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

/**
* binary_tree_height - measures the height of a binary tree
* @tree: A pointer to the root node of the tree to measure the height
*
* Return: if tree is NULL, rturn 0, otherwise, return height
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height) ? (left_height + 1) :
		    (right_height + 1));
}
