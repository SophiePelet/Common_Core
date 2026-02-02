/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:46:03 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/02 11:51:24 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_both(t_node **stack_a, t_node **stack_b, int print)
{
	swap_stack(stack_a, 'a', 0);
	swap_stack(stack_b, 'b', 0);
	if (print == 1)
		ft_printf("%s\n", "ss");
}

void	rotate_both(t_node **stack_a, t_node **stack_b, int print)
{
	rotate_stack(stack_a, 'a', 0);
	rotate_stack(stack_b, 'b', 0);
	if (print == 1)
		ft_printf("%s\n", "rr");
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b, int print)
{
	reverse_rotate_stack(stack_a, 'a', 0);
	reverse_rotate_stack(stack_b, 'b', 0);
	if (print == 1)
		ft_printf("%s\n", "rrr");
}
