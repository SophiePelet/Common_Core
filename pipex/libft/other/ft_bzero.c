/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:47:51 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/05 14:47:55 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

/*
#include <stdlib.h>

int main (void)
{
	char	*mystr;
	char	*dup;
	size_t	nb;

	mystr = "Hello";
	dup = ft_strdup(mystr);
	nb = ft_strlen(mystr);
	ft_bzero(dup, nb);
	printf("%s\n", dup);
}
*/
