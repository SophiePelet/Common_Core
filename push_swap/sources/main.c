/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:45:42 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/29 21:30:13 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
			return (ft_putstr_fd("Error\nNot a valid argument\n", 2), 0);
		head_a = get_num(ac, av);
		if (is_sorted(&head_a))
			return (clean_list(&head_a), 0);
		head_b = NULL;
		size = size_list(&head_a);
		if (size == 2)
			sort_2_nb(&head_a);
		else if (size == 3)
			sort_3_nb(&head_a);
		else if (size == 4)
			sort_4_nb(&head_a, &head_b);
		else
		{
			get_expected_index(&head_a);
			if (size <= 10)
			{
				while (size_list(&head_a) > 3)
				{
					get_actual_index(&head_a);
					rotate_to_min(&head_a);
					push_b(&head_a, &head_b, 1);
				}
			}
			else
				push_chunks_to_b(&head_a, &head_b);
			if (size_list(&head_a) == 3)
				sort_3_nb(&head_a);
			if (head_b != NULL)
			{
				get_expected_index(&head_b);
				get_actual_index(&head_b);
				sorting(&head_a, &head_b);
			}
			get_actual_index(&head_a);
			rotate_to_min(&head_a);
		}
		clean_list(&head_a);
		clean_list(&head_b);
	}
	return (0);
}

/* int	main(int ac, char **av)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*current;
	//int		size;
	

	if (ac == 1)
		return (0);
	if (ac >= 2)
	{
		if (!check_num(ac, av))
			return (ft_putstr_fd("Error\nNot a valid argument\n", 2), 0);
		head_a = get_num(ac, av);
		head_b = NULL;
		//size = size_list(&head_a);
		get_expected_index(&head_a);
		get_actual_index(&head_a);
		push_chunks_to_b(&head_a, &head_b);
		current = head_b;
		while (current)
		{
			printf("lst data: %d\n", current->data);
			printf("lst index: %d\n", current->expected_index);
			printf("lst actual index: %d\n", current->index);
			current = current->next;
		}
		clean_list(&head_a);
		clean_list(&head_b);
	}
	return (0);
} */

/* int	main(int ac, char **av)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;
	t_node	*current;
	int		size;
	int		min;
	int		median;

	i = 0;
	if (ac == 2)
		return (0);
	if (ac > 2)
	{
		if (!check_num(ac, av))
			return (ft_putstr_fd("Error\nNot a valid argument\n", 2), 0);
		head_a = get_num(ac, av);
		head_b = get_num(ac, av);
		size = size_list(&head_a);
		get_expected_index(&head_a);
		get_actual_index(&head_a);
		min = get_min(&head_a);
		median = get_median(&head_a);
		printf("Med: %d\n", median);
		printf("Min: %d\n", min);
		if (ac == 3)
			sort_2_nb(&head_a);
		if (ac == 4)
			sort_3_nb(&head_a);
		if (ac == 5)
			sort_4_nb(&head_a, &head_b);
		current = head_a;
		while (i < size)
		{
			printf("lst data: %d\n", current->data);
			printf("lst index: %d\n", current->expected_index);
			printf("lst actual index: %d\n", current->index);
			current = current->next;
			i++;
		}
		clean_list(&head_a);
		clean_list(&head_b);
	}
	return (0);
} */
