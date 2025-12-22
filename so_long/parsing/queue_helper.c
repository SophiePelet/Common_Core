#include "so_long.h"
#include <stdlib.h>

t_queue	*queue_alloc(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->head = NULL;
	queue->end = NULL;
	queue->size = 0;
	return (queue);
}

int	add_end(t_queue *queue, int x, int y)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->x = x;
	node->y = y;
	node->next = NULL;
	if (queue->size == 0)
		queue->head = node;
	else
		queue->end->next = node;
	queue->end = node;
	queue->size++;
	return (1);
}

int	remove_front(t_queue *queue, int *x, int *y)
{
	t_node	*tmp;

	if (!queue)
		return (0);
	if (queue->size == 0 || queue->head == NULL)
		return (0);
	tmp = queue->head;
	queue->head = tmp->next;
	if (queue->head == NULL)
		queue->end = NULL;
	queue->size--;
	*x = tmp->x;
	*y = tmp->y;
	free(tmp);
	return (1);
}

void	free_all(t_queue *queue)
{
	t_node *current;
	t_node *next;

	if (!queue)
		return ;
	current = queue->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(queue);
}