#include "binary_trees.h"

/**
 * enqueue - adds a binary tree node to the back of a queue.
 * @queue: Pointer to the queue.
 * @node: Pointer to the binary tree node to enqueue.
 */
void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	new_node->node = node;
	new_node->next = NULL;

	if (queue->rear == NULL)
	{
   /* If the queue is empty, both front and rear point to the new node */
		queue->front = queue->rear = new_node;
	} else
	{
   /* Otherwise, add the new node to the rear and update the rear pointer */
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

/**
* dequeue - function that removes  a binary tree node from the
* front of a queue.
* @queue: Pointer to the queue.
* Return: Pointer to the dequeued binary tree node, or NULL
* if the queue is empty.
*/
binary_tree_t *dequeue(queue_t *queue)
{
	if (queue->front == NULL)
	{
		return (NULL);
	}

    /* Get the front node and update the front pointer */
	queue_node_t *front_node = queue->front;

	queue->front = front_node->next;

    /* If the front becomes NULL, update the rear to NULL as well */
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
	binary_tree_t *dequeued_node = front_node->node;

	free(front_node);
	return (dequeued_node);
}

/**
* binary_tree_levelorder - Function to go through a binary tree
* using level-order traversal.
* @tree: Pointer to the root node of the tree to traverse.
* @func: Pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	queue_t *queue = malloc(sizeof(queue_t));

	if (queue == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	queue->front = queue->rear = NULL;

	enqueue(queue, (binary_tree_t *)tree);

	while (queue->front != NULL)
	{
		binary_tree_t *current_node = dequeue(queue);

		func(current_node->n);

       /* Enqueue the left and right children if they exist */
		if (current_node->left != NULL)
		{
			enqueue(queue, current_node->left);
		}
		if (current_node->right != NULL)
		{
			enqueue(queue, current_node->right);
		}
	}
	free(queue);
}
