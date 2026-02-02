/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:07:23 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/02 14:41:35 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// check if number is between INT_MIN and INT_MAX
static int	nb_size(long long int nb)
{
	if (nb < INT_MIN)
		return (0);
	if (nb > INT_MAX)
		return (0);
	return (1);
}

// checks if the given argument is numeric or not
int	check_num(int ac, char **av)
{
	char	**arg;
	int		i;
	int		j;

	i = 1;
	arg = NULL;
	while (i < ac)
	{
		if (arg != NULL)
			ft_free_array(arg);
		arg = ft_split(av[i], 32);
		j = 0;
		while (arg[j] != NULL)
		{
			if (!is_numeric(arg[j]))
				return (ft_putstr_fd("Error\nNot a valid argument\n", 2),
					ft_free_array(arg), 0);
			j++;
		}
		i++;
	}
	ft_free_array(arg);
	return (1);
}

static int	check_double(t_node **head, long long int nb)
{
	int		i;
	t_node	*current;
	int		size;

	i = 0;
	size = size_list(head);
	if (size == 0)
		return (1);
	current = (*head);
	while (i < size)
	{
		if (current->data == nb)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

// calls the checker functions and fill the list if the argument is ok
static int	fill_list(t_node **head, char *arg)
{
	long long int	nb;

	nb = ft_atol(arg);
	if (!nb_size(nb))
		return (ft_putstr_fd("Error\nNumber is out of limits\n", 2), 0);
	if (!check_double(head, nb))
		return (ft_putstr_fd("Error\nDouble encountered\n", 2), 0);
	insert_back(head, nb);
	return (1);
}

// fills the stack with all of the arguments
t_node	*get_num(int ac, char **av)
{
	char	**arg;
	int		i;
	int		j;
	t_node	*head;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		arg = ft_split(av[i], 32);
		j = 0;
		while (arg[j] != NULL)
		{
			if (!fill_list(&head, arg[j]))
				return (ft_free_array(arg), clean_list(&head), NULL);
			j++;
		}
		ft_free_array(arg);
		i++;
	}
	return (head);
}
