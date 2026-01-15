/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:30:41 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/17 15:36:41 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char		*ptr;
	size_t				total;
	unsigned long long	max;

	max = 18446744073709551615ULL;
	if ((nmemb > 0 && size > 0 && max / nmemb < size))
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	size_t elem;
	size_t siz;
	char *mem;

	elem = 4;
	siz = 2;
	mem = ft_calloc(elem, siz);
	mem = calloc(elem, siz);
	printf("%p\n", mem);
	printf("%s\n", mem);
}
*/