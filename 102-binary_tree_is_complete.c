#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - a function.
 * @node: ptr.
 * Return: NULL or .
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - a function.
 * @head: ptr.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - a function.
 * @node: ptr.
 * @head: ptr.
 * @tail: ptr.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - a function.
 * @head: ptr.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - a function that checks
 * if a binary tree is complete.
 * @tree: ptr.
 * Return: 0 or 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *h, *t;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	h = t = create_node((binary_tree_t *)tree);
	if (h == NULL)
		exit(1);

	while (h != NULL)
	{
		if (h->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(h->node->left, h, &t);
		}
		else
			flag = 1;
		if (h->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(h);
				return (0);
			}
			push(head->node->right, h, &t);
		}
		else
			flag = 1;
		pop(&h);
	}
	return (1);
}
