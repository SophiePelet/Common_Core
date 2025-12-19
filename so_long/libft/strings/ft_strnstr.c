/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:54:59 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/12 17:00:46 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit_len;

	i = 0;
	j = 0;
	lit_len = ft_strlen(little);
	if (little[j] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (j < lit_len && (i + j) < len && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <bsd/string.h>

int	main(void)
{
	char	*haystack;
	char	*needle;
	size_t	len;

	haystack = "ABCDEAADDDEFGH";
	needle = "EFGH";
	len  = 30;
	printf("%s\n", strnstr(haystack, needle, len));
	printf("%s\n", ft_strnstr(haystack, needle, len));
}
*/