/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:37:13 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/05 13:23:47 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_pointer(void *ptr)
{
	char				buffer[17];
	unsigned long long	new;
	int					size;
	int					written;
	char				*base_hex;

	new = (unsigned long long)ptr;
	base_hex = "0123456789abcdef";
	written = 0;
	if (new == 0)
	{
		return (ft_putstr("(nil)"));
	}
	size = 16;
	buffer[size] = '\0';
	size--;
	while (new != 0)
	{
		buffer[size] = base_hex[(new % 16)];
		new = new / 16;
		size--;
	}
	written += ft_putstr("0x");
	written += ft_putstr((const char *)&buffer[size + 1]);
	return (written);
}

/* #include <stdio.h>

int	main(void)
{
	char	*test;

	test = "Hello world";
	printf("%d\n", printf("%p", test));
	printf("%d\n", ft_pointer(test));
} */