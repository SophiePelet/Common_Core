/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:13:47 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/05 13:27:00 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	written;

	written = 0;
	if (nb >= 10)
		written += ft_putnbr_unsigned(nb / 10);
	written += ft_putchar(nb % 10 + '0');
	return (written);
}

/* #include <stdio.h>

int	main(void)
{
	unsigned int nbr;

	nbr = -2354952;
	printf(" %d\n", ft_putnbr_unsigned(nbr));
	printf("%u\n", nbr);
} */