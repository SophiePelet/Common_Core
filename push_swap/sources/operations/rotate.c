/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:47:53 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 18:09:27 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	rotate_stack(t_node **stack, char c, int print)
{
	t_node	*head;
	t_node	*new_head;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	new_head = head->next;
	last = last_node(stack);
	new_head->prev = NULL;
	head->next = NULL;
	head->prev = last;
	last->next = head;
	*stack = new_head;
	get_actual_index(stack);
	if (print == 1)
	{
		if (c == 'a')
			ft_printf("%s\n", "ra");
		if (c == 'b')
			ft_printf("%s\n", "rb");
	}
}

void	reverse_rotate_stack(t_node **stack, char c, int print)
{
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = last_node(stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	get_actual_index(stack);
	if (print == 1)
	{
		if (c == 'a')
			ft_printf("%s\n", "rra");
		if (c == 'b')
			ft_printf("%s\n", "rrb");
	}
}
