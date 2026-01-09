/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:06:10 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/17 14:17:47 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	current = (*lst);
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*new;
	t_list	*current;
	int		value1;
	int		value2;
	int		value3;

	value1 = 2;
	value2 = 3;
	value3 = 12;
	head = NULL;
	head = ft_lstnew(&value1);
	head->next = ft_lstnew(&value2);
	new = ft_lstnew(&value3);
	ft_lstadd_back(&head, new);
	current = head;
	while (current != NULL)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
} */