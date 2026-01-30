/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:01 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/30 15:42:48 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	handle_empty_a(t_node **stack_a, t_node **stack_b)
{
	push_a(stack_a, stack_b, 1);
	get_actual_index(stack_a);
	if (*stack_b)
		get_actual_index(stack_b);
}

void	opti_rota_both(t_node **stack_a, t_node **stack_b, int *op_a, int *op_b)
{
	if (*op_b > 0 && *op_a > 0)
	{
		while (*op_a > 0 && *op_b > 0)
		{
			rotate_both(stack_a, stack_b, 1);
			(*op_a)--;
			(*op_b)--;
		}
	}
	if (*op_a < 0 && *op_b < 0)
	{
		while (*op_a < 0 && *op_b < 0)
		{
			reverse_rotate_both(stack_a, stack_b, 1);
			(*op_a)++;
			(*op_b)++;
		}
	}
}

void	opti_rota_a(t_node **stack_a, int *op_a)
{
	while (*op_a > 0)
	{
		rotate_stack(stack_a, 'a', 1);
		(*op_a)--;
	}
	while (*op_a < 0)
	{
		reverse_rotate_stack(stack_a, 'a', 1);
		(*op_a)++;
	}
}

void	opti_rota_b(t_node **stack_b, int *op_b)
{
	while (*op_b > 0)
	{
		rotate_stack(stack_b, 'b', 1);
		(*op_b)--;
	}
	while (*op_b < 0)
	{
		reverse_rotate_stack(stack_b, 'b', 1);
		(*op_b)++;
	}
}

void	sorting(t_node **stack_a, t_node **stack_b)
{
	t_node	*best_b;
	int		op_b;
	t_node	*target_a;
	int		op_a;

	if (*stack_a == NULL && *stack_b != NULL)
		handle_empty_a(stack_a, stack_b);
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
		opti_rota_both(stack_a, stack_b, &op_a, &op_b);
		opti_rota_a(stack_a, &op_a);
		opti_rota_b(stack_b, &op_b);
		push_a(stack_a, stack_b, 1);
		get_actual_index(stack_a);
		if (*stack_b)
			get_actual_index(stack_b);
	}
}
