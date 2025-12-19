/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:35:18 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/17 12:10:13 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = (*lst);
		*lst = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *head;
	t_list *new;
	t_list *current;
	int		value1 = 2;
	int		value2 = 3;
	int		value3 = 1;

	head = ft_lstnew(&value1);
	head->next = ft_lstnew(&value2);
	new = ft_lstnew(&value3);
	ft_lstadd_front(&head, new);
	current = head;
	while (current != NULL)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}
*/