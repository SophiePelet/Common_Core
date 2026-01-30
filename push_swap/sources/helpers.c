/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:47:04 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/30 20:01:26 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(t_node **stack, int print)
{
	t_node	*current;
	int		size;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	size = size_list(stack);
	if (size == 0 || size == 1)
	if (print == 1)
		return (ft_putstr_fd("OK\n", 1), 1);
	while (current && current->next)
	{
		if (current->data > current->next->data)
		{
			if (print == 1)
				ft_putstr_fd("KO\n", 1);
			return (0);
		}
		current = current->next;
	}
	return (ft_putstr_fd("OK\n", 1), 1);
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

void	get_expected_index(t_node **stack)
{
	t_node	*current;
	t_node	*compare;
	int		expected_index;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		expected_index = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->data < current->data)
				expected_index++;
			compare = compare->next;
		}
		current->expected_index = expected_index;
		current = current->next;
	}
}

void push_chunks_to_b(t_node **stack_a, t_node **stack_b)
{
	int count;
	int size_chunk;
	int mid_point;

	count = 0;
	size_chunk = get_chunks(stack_a);
	while (*stack_a)
	{
		mid_point = count + (size_chunk / 2);
		if ((*stack_a)->expected_index <= count)
		{
			push_b(stack_a, stack_b, 1);
			rotate_stack(stack_b, 'b', 1);
			count++;
		}
		else if ((*stack_a)->expected_index <= count + size_chunk)
		{
			push_b(stack_a, stack_b, 1);
			if (*stack_b && (*stack_b)->expected_index <= mid_point)
				rotate_stack(stack_b, 'b', 1);
			count++;
		}
		else
			rotate_stack(stack_a, 'a', 1);
	}
}

void	rotate_to_min_upper(t_node **stack_a, int rotations)
{
	while (rotations > 0)
	{
		rotate_stack(stack_a, 'a', 1);
		rotations--;
	}
}

void	rotate_to_min_lower(t_node **stack_a, int rotations)
{
	while (rotations > 0)
	{
		reverse_rotate_stack(stack_a, 'a', 1);
		rotations--;
	}
}

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
