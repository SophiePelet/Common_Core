/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:47:04 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/02 14:35:37 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

// converts the av in long long number
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

// helper function for rotate to min
void	rotate_to_min_upper(t_node **stack_a, int rotations)
{
	while (rotations > 0)
	{
		rotate_stack(stack_a, 'a', 1);
		rotations--;
	}
}

// helper function for rotate to min
void	rotate_to_min_lower(t_node **stack_a, int rotations)
{
	while (rotations > 0)
	{
		reverse_rotate_stack(stack_a, 'a', 1);
		rotations--;
	}
}

// reorders stack a at the end, brings the min node to the top
void	rotate_to_min(t_node **stack_a)
{
	t_node	*min_node;
	int		position;
	int		size;
	int		rotations;

	if (!stack_a || !*stack_a)
		return ;
	min_node = get_min_node(stack_a);
	if (!min_node)
		return ;
	position = min_node->index;
	size = size_list(stack_a);
	if (position <= size / 2)
	{
		rotations = position;
		rotate_to_min_upper(stack_a, rotations);
	}
	else
	{
		rotations = size - position;
		rotate_to_min_lower(stack_a, rotations);
	}
}
