/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:07:38 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/05 13:26:34 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_hexl(unsigned int nb)
{
	int	written;

	written = 0;
	if (nb >= 16)
		written += ft_putnbr_hexl(nb / 16);
	if (nb % 16 <= 9)
		written += ft_putchar(nb % 16 + '0');
	else if (nb % 16 >= 10)
		written += ft_putchar((nb % 16) - 10 + 'a');

	return (written);
}

/* #include <stdio.h>

int	main(void)
{
	int nb;

	nb = 42565154;
	printf("%x\n", nb);
	printf(" %d\n", ft_putnbr_hexl(nb));
} */