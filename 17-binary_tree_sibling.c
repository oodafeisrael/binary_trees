#include "binary_trees.h"

/**
* binary_tree_sibling - Function to find the sibling of a node in
* a binary tree.
* @node: node Pointer to the node for which to find the sibling.
* Return: Pointer to the sibling node or NULL if node is NULL, parent is
* NULL, or node has no sibling.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

/* check if the input node is the left or right child of its parent */
	if (node->parent->left == node)
	{
/* If the input node is the left child, return the right child (sibling) */
		return (node->parent->right);
	}
/* If the input node is the right child, return the left child (sibling) */
	return (node->parent->left);
}
