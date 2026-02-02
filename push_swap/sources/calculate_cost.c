/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:41:53 by sophie            #+#    #+#             */
/*   Updated: 2026/02/02 14:31:43 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// find the number on top of which the number from stack b is supposed to go
// it's the second smallest of the stack a
t_node	*second_smallest(t_node **stack_a, t_node *current_b)
{
	t_node	*current;
	t_node	*small;

	current = *stack_a;
	small = NULL;
	while (current)
	{
		if (current->expected_index > current_b->expected_index)
		{
			if (small == NULL
				|| current->expected_index < small->expected_index)
				small = current;
		}
		current = current->next;
	}
	return (small);
}

// calculates the number of operations to get a number to the top the stack
int	nb_get_to_top(t_node *node, t_node **stack)
{
	int	position;
	int	size;

	position = node->index;
	size = size_list(stack);
	if (position <= size / 2)
		return (position);
	else
		return (-(size - position));
}

// calculates moves when rotations on a and b are in the same direction
static int	same_sign_stacks(int move_a, int move_b)
{
	int	total_moves;

	if (abs_value(move_a) > abs_value(move_b))
		total_moves = abs_value(move_a);
	else
		total_moves = abs_value(move_b);
	return (total_moves);
}

// calculates the number of operations to bring the second smallest of stack a
// and a node of b at the good position
static int	nb_move_good_pos(t_node *current_b, t_node **stack_a,
		t_node **stack_b)
{
	t_node	*sec_small;
	t_node	*target;
	int		move_a;
	int		move_b;
	int		total_moves;

	sec_small = second_smallest(stack_a, current_b);
	if (sec_small == NULL)
	{
		target = get_min_node(stack_a);
		if (target == NULL)
			return (INT_MAX);
		move_a = nb_get_to_top(target, stack_a);
	}
	else
		move_a = nb_get_to_top(sec_small, stack_a);
	move_b = nb_get_to_top(current_b, stack_b);
	if ((move_a > 0 && move_b > 0) || (move_a < 0 && move_b < 0))
		total_moves = same_sign_stacks(move_a, move_b);
	else
		total_moves = abs_value(move_a) + abs_value(move_b);
	return (total_moves);
}

// finds the node in b that costs the less operations
t_node	*calculate_cost(t_node **stack_a, t_node **stack_b)
{
	int		to_top;
	t_node	*current_b;
	int		greed;
	t_node	*greed_node;

	current_b = (*stack_b);
	greed = INT_MAX;
	greed_node = NULL;
	while (current_b)
	{
		to_top = nb_move_good_pos(current_b, stack_a, stack_b);
		if (to_top < greed)
		{
			greed = to_top;
			greed_node = current_b;
		}
		current_b = current_b->next;
	}
	return (greed_node);
}
