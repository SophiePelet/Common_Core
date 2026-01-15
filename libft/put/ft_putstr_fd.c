/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:52:12 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/07 15:22:52 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	write(fd, &s[i], s_len);
}

/*
int	main(void)
{
	ft_putstr_fd("This goes to standard output.\n", 1);
	ft_putstr_fd("This is an error message.\n", 2);
}
*/
