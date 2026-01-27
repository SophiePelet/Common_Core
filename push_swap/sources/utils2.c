/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:44 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 17:50:48 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(t_node **stack)
{
	t_node	*current;
	int		size;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	size = size_list(stack);
	if (size == 0 || size == 1)
		return (1);
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}


