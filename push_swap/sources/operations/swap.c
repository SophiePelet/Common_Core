/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:45:42 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 17:29:02 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_stack(t_node **stack, char c, int print)
{
	int	content;
	int	expected_index;
	int	actual_index;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	content = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = content;
	expected_index = (*stack)->expected_index;
	(*stack)->expected_index = (*stack)->next->expected_index;
	(*stack)->next->expected_index = expected_index;
	actual_index = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = actual_index;
	if (print == 1)
	{
		if (c == 'a')
			ft_printf("%s\n", "sa");
		else if (c == 'b')
			ft_printf("%s\n", "sb");
	}
}
