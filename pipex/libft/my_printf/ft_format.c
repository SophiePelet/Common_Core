/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:08:30 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/17 14:57:00 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_format(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hexl(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_putnbr_hexu(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else
		return (0);
}
