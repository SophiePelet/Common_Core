/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:18:39 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/11 12:23:30 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	total;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total = dst_len + src_len;
	if (dst_len >= siz)
		return (siz + src_len);
	while (src[i] != '\0' && i < (siz - dst_len - 1))
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (total);
}
/*
#include <bsd/string.h>

int	main(void)
{
	char dest_buffer[20];
	const char *initial = "Hello";
	const char *to_add = "World";
	strlcpy(dest_buffer, initial, 20);
	printf("%zu\n", ft_strlcat(dest_buffer, to_add, 3));
}
*/