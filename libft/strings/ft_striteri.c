/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:46:25 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/10 15:26:36 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
void	test(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
        *c = ft_toupper(*c);
	}
	else
		*c = '-';
}

int	main(void)
{
	char str[] = "abcdeF";

	ft_striteri(str, test);
	printf("%s\n", str);
}
*/