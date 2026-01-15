/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:50:12 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/11 15:12:32 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	int_len(int num)
{
	size_t		i;
	long long	nbr;

	i = 0;
	nbr = (long long)num;
	if (nbr == 0)
		i++;
	if (nbr < 0)
	{
		i += 1;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*array;
	long long		nbr;
	size_t			len;

	len = int_len(n);
	nbr = (long long)n;
	array = ft_calloc((len + 1), sizeof(char));
	if (!array)
		return (NULL);
	if (nbr == 0)
		array[0] = '0';
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		array[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		array[0] = '-';
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	int n;

	n = -2147483648;
	printf("%s\n", ft_itoa(n));
}
*/