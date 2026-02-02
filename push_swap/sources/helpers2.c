/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:52:38 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/02 14:38:33 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// finds the index of a node in the list
void	get_actual_index(t_node **stack)
{
	t_node	*current;
	int		i;

	if (!stack || !*stack)
		return ;
	i = 0;
	current = *stack;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

// finds the index of the min of the list
int	get_min(t_node **stack)
{
	int		min;
	t_node	*current;
	int		i;

	if (!stack || !*stack)
		return (-1);
	min = (*stack)->expected_index;
	current = *stack;
	i = 0;
	while (current)
	{
		if (current->expected_index < min)
			min = current->expected_index;
		current = current->next;
	}
	current = *stack;
	while (current->expected_index != min)
	{
		i++;
		current = current->next;
	}
	return (i);
}

// calculates the size of the chunks needed depending on the size of the list
int	get_chunks(t_node **stack_a)
{
	int	size;

	size = size_list(stack_a);
	if (size <= 5)
		return (3);
	else if (size <= 16)
		return (4);
	else if (size <= 100)
		return (25);
	else if (size <= 500)
		return (30);
	else
		return (size / 15);
}

// finds and returns the min node of the list
t_node	*get_min_node(t_node **stack)
{
	t_node	*min_node;
	t_node	*current;

	if (!stack || !*stack)
		return (NULL);
	min_node = *stack;
	current = *stack;
	while (current)
	{
		if (current->expected_index < min_node->expected_index)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

// finds the index where the node should be if the list was sorted
void	get_expected_index(t_node **stack)
{
	t_node	*current;
	t_node	*compare;
	int		expected_index;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		expected_index = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->data < current->data)
				expected_index++;
			compare = compare->next;
		}
		current->expected_index = expected_index;
		current = current->next;
	}
}
