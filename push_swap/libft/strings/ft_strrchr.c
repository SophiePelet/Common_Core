/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:02:17 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/11 11:42:04 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*p;
	unsigned char	target;

	len = ft_strlen(s);
	p = (unsigned char *)s;
	target = (unsigned char)c;
	if (target == '\0')
		return ((char *)&p[len]);
	while (len > 0)
	{	
		len--;
		if (p[len] == target)
			return ((char *)&p[len]);
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str;
	int			chr;

	str = "Bonjour";
	chr = 'B';
	printf("%p\n", strrchr(str, chr));
	printf("%p\n", ft_strrchr(str, chr));
}
*/