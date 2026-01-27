/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:04:15 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 17:54:08 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	insert_front(t_node **node, int content)
{
	t_node	*new;

	new = create_node(content);
	if (*node == NULL)
		*node = new;
	else
	{
		new->next = (*node);
		(*node)->prev = new;
		*node = new;
	}
}

void	insert_back(t_node **node, int content)
{
	t_node	*current;
	t_node	*new;

	new = create_node(content);
	if (*node == NULL)
	{
		(*node) = new;
		return ;
	}
	current = (*node);
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
}

void	clean_list(t_node **node)
{
	t_node	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
}

int	size_list(t_node **node)
{
	t_node	*current;
	int		i;

	i = 0;
	current = (*node);
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
