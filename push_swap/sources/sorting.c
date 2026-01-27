/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:01 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 20:28:26 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_chunks_to_b(t_node **stack_a, t_node **stack_b)
{
	int	count;
	int	size_chunk;

	if (!stack_a || !*stack_a)
		return ;
	count = 0;
	size_chunk = get_chunks(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->expected_index <= count)
		{
			push_b(stack_a, stack_b, 1);
			rotate_stack(stack_b, 'b', 1);
			count++;
		}
		else if ((*stack_a)->expected_index <= count + size_chunk)
		{
			push_b(stack_a, stack_b, 1);
			count++;
		}
		else
		{
			rotate_stack(stack_a, 'a', 1);
		}
	}
}

int	second_smallest(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		match;

	current = *stack_a;
	match = LONG_MAX;
	while (current)
	{
		if (current->expected_index > (*stack_b)->expected_index)
		{
			if (current->expected_index < match)
				match = current->expected_index;
		}
		current = current->next;
	}
	return (match);
}
