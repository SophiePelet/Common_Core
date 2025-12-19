/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:35:55 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/17 14:57:24 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_hexu(unsigned int nb)
{
	int	written;

	written = 0;
	if (nb >= 16)
	{
		written += ft_putnbr_hexu(nb / 16);
	}
	if (nb % 16 >= 0 && nb % 16 <= 9)
	{
		written += ft_putchar(nb % 16 + '0');
	}
	if (nb % 16 >= 10 && nb % 16 <= 15)
	{
		written += ft_putchar((nb % 16) - 10 + 'A');
	}
	return (written);
}

/* #include <stdio.h>

int	main(void)
{
	int nb;

	nb = 1512315;
	printf("%X\n", nb);
	printf(" %d\n", ft_putnbr_hexu(nb));
} */