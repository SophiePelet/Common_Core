/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:13:43 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/07 13:15:30 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	while (src[i] != '\0' && i < (siz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
int	main(void)
{
	const char *source = "bonjour";	
	size_t 		len;
	char		desti[2];

	len = 2;
	printf("%zu\n", ft_strlcpy(desti, source, len));
	printf("%s\n", desti);
}
*/