/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:39:54 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/30 15:41:51 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strlen_gnl(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_bzero_gnl(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	unsigned char		*ptr;
	size_t				total;
	unsigned long long	max;

	max = 18446744073709551615ULL;
	if ((nmemb > 0 && size > 0 && max / nmemb < size))
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero_gnl(ptr, total);
	return (ptr);
}

char	*ft_strdup_index(char const *src, size_t index)
{
	char	*dup;
	size_t	srclen;
	size_t	duplen;
	size_t	i;

	i = 0;
	srclen = ft_strlen_gnl(src);
	if (srclen < index)
		return (NULL);
	duplen = srclen - index;
	dup = malloc(sizeof(char) * (duplen + 1));
	if (!dup)
		return (NULL);
	while (src[index] != '\0')
	{
		dup[i] = src[index];
		index++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1)
		return (new = ft_strdup_index(s2, 0));
	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
