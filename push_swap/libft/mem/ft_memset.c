/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:49:59 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/05 14:50:01 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*var;

	var = s;
	while (n > 0)
	{
		*var = c;
		var++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[50] = "GeeksForGeeks is for programming geeks.";

	printf("Before ft_memset(): %s\n", str);
	ft_memset(str + 13, '.', 8*sizeof(char));
	printf("After ft_memset():  %s\n", str);
	return (0);
}
*/
