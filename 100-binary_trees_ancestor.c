#include "binary_trees.h"

/**
 * is_ancestor - function to check if a node is an ancestor of another node.
 * @ancestor: This is a pointer to a node that you want to check if
 * it is an ancestor of another node.
 * @node: his is a pointer to the node for which you want to check if
 * ancestor is an ancestor.
 *
 * Return: 1 if ancestor is indeed an ancestor of node, otherwise, 0
 */
int is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node)
{
	while (node != NULL)
	{
		if (node == ancestor)
		{
			return (1);
		}
		node = node->parent;
	}
	return (0);
}

/**
 * binary_trees_ancestor - Function to find the lowest common ancestor
 * of two nodes in a binary tree.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor node or NULL if
 * no common ancestor is found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor = first;

	while (ancestor != NULL)
	{
		if (is_ancestor(ancestor, second))
		{
			return ((binary_tree_t *)ancestor);
		}
	ancestor = ancestor->parent;
	}
	return (NULL);
}
