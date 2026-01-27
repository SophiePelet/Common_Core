/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthcar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:40:24 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/07 15:47:41 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main(void)
{
    char    c;
    int     fd;

    c = 'e';
    fd = 2;
    ft_putchar_fd(c, fd);
}
*/