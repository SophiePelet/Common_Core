/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:47:04 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/27 14:44:34 by sopelet          ###   ########.fr       */
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

static long long	exec_atol(char *nptr, int sign, int pos)
{
	int			i;
	long long	res;

	i = pos;
	res = 0;
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		if (sign == 1)
		{
			if (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10 && (nptr[i]
						- '0') > 7))
				return (LLONG_MAX);
		}
		else
		{
			if (res > -(LLONG_MIN / 10) || (res == -(LLONG_MIN / 10) && (nptr[i]
						- '0') > 8))
				return (LLONG_MIN);
		}
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res);
}

long long	ft_atol(char *n)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	sign = 1;
	while (n[i] == 32 || (n[i] >= 9 && n[i] <= 13))
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign = -sign;
		i++;
	}
	if (n[i] == '-' || n[i] == '+')
		return (0);
	result = exec_atol(n, sign, i);
	return (result * sign);
}
