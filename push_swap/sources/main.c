/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:45:42 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/02 14:55:56 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

//pushes all a elments to be depending on their expected index
void	push_chunks_to_b(t_node **stack_a, t_node **stack_b)
{
	int	count;
	int	size_chunk;

	count = 0;
	size_chunk = get_chunks(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->expected_index <= count)
		{
			push_b(stack_a, stack_b, 1);
			rotate_stack(stack_b, 'b', 1);
			count++;
		}
		else if ((*stack_a)->expected_index <= count + size_chunk)
		{
			push_b(stack_a, stack_b, 1);
			count++;
		}
		else if (last_node(stack_a)->expected_index <= count + size_chunk)
			reverse_rotate_stack(stack_a, 'a', 1);
		else
			rotate_stack(stack_a, 'a', 1);
	}
}

//handles lists that are between 2 and 4 numbers
static void	very_small_lists(int size, t_node **head_a, t_node **head_b)
{
	size = size_list(head_a);
	if (size == 2)
		sort_2_nb(head_a);
	else if (size == 3)
		sort_3_nb(head_a);
	else if (size == 4)
		sort_4_nb(head_a, head_b);
}

//handles lists <= 10 numbers and push chunks to b if they are bigger than 10
static void	is_big_list(t_node **head_a, t_node **head_b, int size)
{
	get_expected_index(head_a);
	if (size <= 10)
	{
		while (size_list(head_a) > 3)
		{
			get_actual_index(head_a);
			rotate_to_min(head_a);
			push_b(head_a, head_b, 1);
		}
	}
	else
		push_chunks_to_b(head_a, head_b);
}

//handles lists bigger than 10 after all elements were pushed to b
static void	handle_big_lists(t_node **head_a, t_node **head_b, int size)
{
	is_big_list(head_a, head_b, size);
	if (size_list(head_a) == 3)
		sort_3_nb(head_a);
	if (*head_b != NULL)
	{
		get_expected_index(head_b);
		get_actual_index(head_b);
		sorting(head_a, head_b);
	}
	get_actual_index(head_a);
	rotate_to_min(head_a);
}

int	main(int ac, char **av)
{
	t_node	*head_a;
	t_node	*head_b;
	int		size;

	if (ac == 1)
		return (0);
	if (ac >= 2)
	{
		if (!check_num(ac, av))
			exit(1);
		head_a = get_num(ac, av);
		if (head_a == NULL || size_list(&head_a) == 1)
			return (0);
		if (is_sorted(&head_a))
			return (clean_list(&head_a), 0);
		head_b = NULL;
		size = size_list(&head_a);
		if (size <= 4)
			very_small_lists(size, &head_a, &head_b);
		else
			handle_big_lists(&head_a, &head_b, size);
		clean_list(&head_a);
		clean_list(&head_b);
	}
	return (0);
}
