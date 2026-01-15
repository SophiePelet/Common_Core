/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:20:07 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/17 12:07:34 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*desti;
	char	*source;

	if (n == 0 || dest == src)
		return (dest);
	desti = (char *)dest;
	source = (char *)src;
	if (desti < source)
	{
		while (n--)
			*desti++ = *source++;
	}
	else if (desti > source)
	{
		while (n > 0)
		{
			desti[n - 1] = source[n - 1];
			n--;
		}
	}
	return (dest);
}

/*
#include <string.h>

int	main(void)
{
	size_t		size;
	const char	*src;
	char		dst[50];

	size = 5;
	src = "helloworld";
	memmove(dst, src, size);
	dst[size] = '\0';
	printf("%s\n", dst);
	ft_memmove(dst, src, size);
	dst[size] = '\0';
	printf("%s\n", (char *)ft_memmove(dst, src, size));
}
*/