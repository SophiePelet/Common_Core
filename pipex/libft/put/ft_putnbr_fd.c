/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:51:42 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/17 12:06:55 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int num, int fd)
{
	char	last_digit;

	if (num < 0)
	{
		if (num == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	last_digit = num % 10 + '0';
	ft_putchar_fd(last_digit, fd);
}

/*
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	ft_putnbr_fd(atoi(av[1]), atoi(av[2]));
}
*/