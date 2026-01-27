/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:52:38 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 19:36:13 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

/* int	get_median(t_node **stack)
{
	t_node	*current;
	int		size;

	current = *stack;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size / 2);
} */

int	get_chunks(t_node **stack_a)
{
	int	size;
	int	chunk_size;

	size = size_list(stack_a);
	if (size <= 100)
		chunk_size = 15;
	else if (size <= 500)
		chunk_size = 35;
	else
		chunk_size = 45;
	return (chunk_size);
}