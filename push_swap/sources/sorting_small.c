/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:24:13 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/30 21:10:20 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_2_nb(t_node **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_stack(stack_a, 'a', 1);
}

void	sort_3_nb(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (!stack_a || !(*stack_a))
		return ;
	if (second > first && second > third && first < third)
	{
		swap_stack(stack_a, 'a', 1);
		rotate_stack(stack_a, 'a', 1);
	}
	if (second > third && second < first)
	{
		swap_stack(stack_a, 'a', 1);
		reverse_rotate_stack(stack_a, 'a', 1);
	}
	if (second < first && second < third && first > third)
		rotate_stack(stack_a, 'a', 1);
	if (second < first && second < third && first < third)
		swap_stack(stack_a, 'a', 1);
	if (second > first && second > third && first > third)
		reverse_rotate_stack(stack_a, 'a', 1);
}

void	sort_4_nb(t_node **stack_a, t_node **stack_b)
{
	int		min_index;
	t_node	*current;

	current = *stack_a;
	if (is_sorted(&current))
		return ;
	min_index = get_min(stack_a);
	if (min_index == 1)
		swap_stack(stack_a, 'a', 1);
	if (min_index == 2)
	{
		rotate_stack(stack_a, 'a', 1);
		rotate_stack(stack_a, 'a', 1);
	}
	if (min_index == 3)
		reverse_rotate_stack(stack_a, 'a', 1);
	push_b(stack_a, stack_b, 1);
	sort_3_nb(stack_a);
	push_a(stack_a, stack_b, 1);
}
