/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:47:46 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/05 13:25:41 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/* #include <stdio.h>

int	main(void)
{
	printf(" %d\n", ft_printf("number:%d", 1215));
	printf(" %d\n", ft_printf("number:%i", 54945));
	printf(" %d\n", ft_printf("char:%c", 'c'));
	printf(" %d\n", ft_printf("string:%s", "pookie"));
	printf(" %d\n", ft_printf("percentage:100%%"));
	printf(" %d\n", ft_printf("unsigned decimal:%u", -256456));
	printf(" %d\n", ft_printf("lower hex:%x", 25656));
	printf(" %d\n", ft_printf("upper hex:%X", 21566));
	printf(" %d\n", ft_printf("a pointer:%p", "Hello"));
	printf(" %d\n", ft_printf("%s", NULL));
	printf(" %d\n", ft_printf(NULL));
	printf(" %d\n", ft_printf(1));
} */