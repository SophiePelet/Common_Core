/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:10:41 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/05 13:27:06 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr(int nb)
{
	int	written;

	written = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		ft_putchar('-');
		written += 1;
		nb = -nb;
	}
	if (nb >= 10)
		written += ft_putnbr(nb / 10);
	written += ft_putchar(nb % 10 + '0');
	return (written);
}

/* #include <stdio.h>

int	main(void)
{
	int	nbr;

	nbr = 56512;
	printf(" %d\n", ft_putnbr(nbr));
} */