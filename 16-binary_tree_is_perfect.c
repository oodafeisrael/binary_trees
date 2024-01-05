#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
* binary_tree_is_full -- Function to check if a binary tree is full.
* @tree: tree Pointer to the root node of the tree.
*
* Return: 1 if the tree is full, 0 otherwise.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	{
		return (1);
	}
	if (tree->left && tree->right)
	{
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	}
	return (0);
}
/**
* binary_tree_is_perfect - Function to check if a binary
* tree is perfect.
* @tree: tree Pointer to the root node of the tree.
* Return:  1 if the tree is perfect, 0 otherwise.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL || !binary_tree_is_full(tree))
	{
		return (0);
	}

	int height = binary_tree_height(tree);
	int level = 0;

      /* Traverse the tree to check if all leaves are at the same depth*/
	while (tree)
	{
		if ((tree->left == NULL && tree->right == NULL) &&
				level < height)
		{
			return (0);
		}
		if (tree->left)
		{
			tree = tree->left;
			level++;
		} else
		{
			tree = tree->right;
		}
	}
	return (1);
}

/**
* binary_tree_height - measures the height of a binary tree
*
* @tree: pointer to the root node of the tree to measure the height.
* Return: 0 If tree is NULL, or the height
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
