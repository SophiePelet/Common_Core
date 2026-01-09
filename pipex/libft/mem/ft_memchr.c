/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:49:20 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/12 18:35:59 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	chr;
	size_t			i;

	mem = (unsigned char *)s;
	chr = c;
	i = 0;
	while (i < n)
	{
		if (mem[i] == chr)
			return (&mem[i]);
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
int	main(void)
{
	const char *mystr;
	int chr;
	size_t bytes;

	mystr = "hello world";
	chr = 'o';
	bytes = 7;
	printf("%p\n", memchr(mystr, chr, bytes));
	printf("%p\n", ft_memchr(mystr, chr, bytes));
}
*/