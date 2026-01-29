/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:52:38 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/29 21:49:24 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

int	get_chunks(t_node **stack_a)
{
	int	size;

	size = size_list(stack_a);
	if (size <= 5)
		return (3);
	else if (size <= 16)
		return (4);
	else if (size <= 100)
		return (27);
	else if (size <= 500)
		return (30);
	else
		return (size / 15);
}

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
