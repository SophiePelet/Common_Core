/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:27:51 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 18:09:15 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b, int print)
{
	t_node	*head_b;

	if (!stack_b || !(*stack_b))
		return ;
	head_b = *stack_b;
	*stack_b = head_b->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	head_b->next = *stack_a;
	head_b->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = head_b;
	*stack_a = head_b;
	get_actual_index(stack_a);
	get_actual_index(stack_b);
	if (print == 1)
		ft_printf("%s\n", "pa");
}

void	push_b(t_node **stack_a, t_node **stack_b, int print)
{
	t_node	*head_a;

	if (!stack_a || !(*stack_a))
		return ;
	head_a = *stack_a;
	*stack_a = head_a->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	head_a->next = *stack_b;
	head_a->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = head_a;
	*stack_b = head_a;
	get_actual_index(stack_a);
	get_actual_index(stack_b);
	if (print == 1)
		ft_printf("%s\n", "pb");
}
