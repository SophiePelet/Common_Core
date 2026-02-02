/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:02:10 by sophie            #+#    #+#             */
/*   Updated: 2026/02/02 17:06:06 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	make_push_and_swap(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		return (push_a(stack_a, stack_b, 0), 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (push_b(stack_a, stack_b, 0), 1);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		return (swap_stack(stack_a, 'a', 0), 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (swap_stack(stack_a, 'b', 0), 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (swap_both(stack_a, stack_b, 0), 1);
	return (0);
}

static int	make_rotations(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		return (rotate_stack(stack_a, 'a', 0), 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rotate_stack(stack_b, 'b', 0), 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		return (rotate_both(stack_a, stack_b, 0), 1);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		return (reverse_rotate_stack(stack_a, 'a', 0), 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (reverse_rotate_stack(stack_b, 'b', 0), 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (reverse_rotate_both(stack_a, stack_b, 0), 1);
	return (0);
}

static int	make_operations(t_node **stack_a, t_node **stack_b, char *line)
{
	if (!make_push_and_swap(stack_a, stack_b, line) && !make_rotations(stack_a,
			stack_b, line))
		return (0);
	return (1);
}

static void	get_commands(int fd, t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(fd, 0);
	while (line)
	{
		if (!make_operations(stack_a, stack_b, line))
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			get_next_line(0, 1);
			return ;
		}
		free(line);
		line = get_next_line(fd, 0);
	}
	if (*stack_a && !*stack_b)
	{
		if (!is_sorted(stack_a))
			ft_putstr_fd("KO\n", 2);
		else
			ft_putstr_fd("OK\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 2);
	return ;
}

int	main(int ac, char **av)
{
	t_node	*head_a;
	t_node	*head_b;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (!check_num(ac, av))
			exit(1);
	}
	if (ac > 2)
	{
		if (!check_num(ac, av))
			exit(1);
		head_a = get_num(ac, av);
		if (head_a == NULL)
			return (1);
		head_b = NULL;
		get_commands(0, &head_a, &head_b);
		clean_list(&head_a);
		clean_list(&head_b);
	}
	return (0);
}
