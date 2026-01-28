/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:02:44 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/28 16:38:22 by sophie           ###   ########.fr       */
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