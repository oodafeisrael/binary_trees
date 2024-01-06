#include "binary_trees.h"

/**
* binary_tree_is_complete - Check if a binary tree is complete.
* @tree: Pointer to the root node of the tree to check.
* Return: 1 if the tree is complete, 0 otherwise.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

    /* Create a queue for level-order traversal */
	queue_t *queue = malloc(sizeof(queue_t));

	if (queue == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	queue->front = queue->rear = NULL;

    /* Flag to indicate if we have encountered a non-full node */
	int non_full_node = 0;

    /* Enqueue the root node to start level-order traversal */
	enqueue(queue, (binary_tree_t *)tree);

    /* Continue the traversal until the queue is empty */
	while (queue->front != NULL)
	{
        /* Remove the front node from the queue */
		binary_tree_t *current_node = dequeue(queue);
		if (current_node == NULL)
		{
			non_full_node = 1;
		} else
		{
			if (non_full_node)
			{
				free(queue);
				return (0);
			}
      /*  Enqueue the left and right children if they exist */
			enqueue(queue, current_node->left);
			enqueue(queue, current_node->right);
		}
	}
    /* If we reached here, the tree is complete */
	free(queue);
	return (1);
}
