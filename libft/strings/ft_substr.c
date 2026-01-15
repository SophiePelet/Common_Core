/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:47:23 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/11 15:44:12 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	char			*sub_s;
	size_t			i;

	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if ((start + len) > len_s)
		len = len_s - start;
	sub_s = ft_calloc(sizeof(char), len + 1);
	if (!sub_s)
		return (NULL);
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	return (sub_s);
}

/*
int	main(void)
{
	const char		*str;
	unsigned int	start;
	size_t			lenght;

	str = "hello, how are you?";
	start = 30;
	lenght = 2;
	printf("%s\n", ft_substr(str, start, lenght));
}
*/