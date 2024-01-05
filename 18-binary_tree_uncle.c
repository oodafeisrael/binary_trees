#include "binary_trees.h"

/**
 * binary_tree_uncle - Function to find the uncle of a node in a binary tree.
 * @node: Pointer to the node for which to find the uncle.
 * Return: Pointer to the uncle node or NULL if node is NULL or has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
	{
		return (NULL);
	}

	if (node->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent->parent == NULL)
	{
		return (NULL);
	}

	binary_tree_t *grandparent = node->parent->parent
;
	if (grandparent->left == node->parent)
	{
		return (grandparent->right);
	}
	if (grandparent->right == node->parent)
	{
		return (grandparent->left);
	}

	return (NULL);
}
