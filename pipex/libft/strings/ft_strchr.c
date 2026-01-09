/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:21:51 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/11 11:18:32 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	target;

	i = 0;
	target = (unsigned char)c;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == target)
			return ((char *)&s[i]);
		i++;
	}
	if (target == '\0')
		return (((char *)&s[i]));
	return (NULL);
}

/*
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	const char	*str;
	int			chr;

	str = "how are you?";
	chr = 'd';
	printf("%s\n", strchr(str, chr));
	printf("%s\n", ft_strchr(str, chr));
}
*/