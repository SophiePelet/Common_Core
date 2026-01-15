/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:15:19 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/17 14:05:06 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list  *head;
	int     value1;
	int     value2;
	int     value3;

	value1 = 1;
	value2 = 2;
	value3 = 3;
	head = ft_lstnew(&value1);
	head->next = ft_lstnew(&value2);
	head->next->next = ft_lstnew(&value3);
	printf("%d\n", ft_lstsize(head));
}
*/