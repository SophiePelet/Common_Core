/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:01 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/28 18:02:06 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static t_node *second_smallest(t_node **stack_a, t_node *current_b)
{
	t_node *current;
	t_node *small;

	current = *stack_a;
	small = NULL;
	while (current)
	{
		if (current->expected_index > current_b->expected_index)
		{
			if (small == NULL || current->expected_index < small->expected_index)
				small = current;
		}
		current = current->next;
	}
	return (small);
}

static int nb_get_to_top(t_node *node, t_node **stack)
{
	int position;
	int size;

	position = node->index;
	size = size_list(stack);
	if (position <= size / 2)
		return (position);
	else
		return (-(size - position));
}

static int nb_move_good_pos(t_node *current_b, t_node **stack_a, t_node **stack_b)
{
	t_node *sec_small;
	t_node	*target;
	int top_a;
	int top_b;
	int to_top;

	sec_small = second_smallest(stack_a, current_b);
	if (sec_small == NULL)
	{
		target = get_min_node(stack_a);
        if (target == NULL)
            return (INT_MAX);
		top_a = abs_value(nb_get_to_top(get_min_node(stack_a), stack_a));
	}
	else
		top_a = abs_value(nb_get_to_top(sec_small, stack_a));
	top_b = abs_value(nb_get_to_top(current_b, stack_b));
	to_top = top_a + top_b;
	return (to_top);
}

static t_node *calculate_cost(t_node **stack_a, t_node **stack_b)
{
	int to_top;
	t_node *current_b;
	int greed;
	t_node *greed_node;

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

void	sorting(t_node **stack_a, t_node **stack_b)
{
	t_node	*best_b;
	int		op_b;
	t_node	*target_a;
	int		op_a;

	if (*stack_a == NULL && *stack_b != NULL)
    {
        push_a(stack_a, stack_b, 1);
        get_actual_index(stack_a);
        get_actual_index(stack_b);
    }
	while (*stack_b)
	{
		best_b = calculate_cost(stack_a, stack_b);
		if (best_b == NULL)
		break;
		op_b = nb_get_to_top(best_b, stack_b);
		target_a = second_smallest(stack_a, best_b);
		if (target_a == NULL)
			target_a = get_min_node(stack_a);
		op_a = nb_get_to_top(target_a, stack_a);
		if (op_b > 0 && op_a > 0)
		{
			while (op_a > 0 && op_b > 0)
			{
				rotate_both(stack_a, stack_b, 1);
				op_a--;
				op_b--;
			}
		}
		if (op_a < 0 && op_b < 0)
		{
			while (op_a < 0 && op_b < 0)
			{
				reverse_rotate_both(stack_a, stack_b, 1);
				op_a++;
				op_b++;
			}
		}
		while (op_a > 0)
        {
            rotate_stack(stack_a, 'a', 1);
            op_a--;
        }
        while (op_a < 0)
        {
            reverse_rotate_stack(stack_a, 'a', 1);
            op_a++;
        }
        while (op_b > 0)
        {
            rotate_stack(stack_b, 'b', 1);
            op_b--;
        }
        while (op_b < 0)
        {
            reverse_rotate_stack(stack_b, 'b', 1);
            op_b++;
        }
        push_a(stack_a, stack_b, 1);
        get_actual_index(stack_a);
        get_actual_index(stack_b);
	}
}
