/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:36:18 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/17 18:32:05 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*head;
	int		value1;
	int		value2;
	int		value3;
	t_list	*last;

	value1 = 1;
	value2 = 2;
	value3 = 3;
	head = ft_lstnew(&value1);
	head->next = ft_lstnew(&value2);
	head->next->next = ft_lstnew(&value3);
	last = ft_lstlast(head);
	printf("%d\n", *(int *)last->content);
}
*/