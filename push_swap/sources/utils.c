/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:44 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/02 11:51:16 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		while (str[i] != '\0')
		{
			if (!is_digit(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_node	*last_node(t_node **node)
{
	t_node	*current;

	current = *node;
	while (current != NULL && current->next != NULL)
		current = current->next;
	return (current);
}

int	abs_value(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

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
