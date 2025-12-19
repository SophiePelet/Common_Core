/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:37:31 by sopelet           #+#    #+#             */
/*   Updated: 2025/11/11 15:13:33 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*new_str(const char *former, size_t start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (len <= 0 || start >= ft_strlen(former))
		return (ft_strdup(""));
	new = ft_calloc(sizeof(char), len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = former[start + i];
		i++;
	}
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_in_set(set, s1[i]))
		i++;
	while (is_in_set(set, s1[j]))
		j--;
	return (new_str(s1, i, ((j - (i - 1)))));
}
/*
int	main(void)
{
	char    *to_trim;
	char    *set;

	to_trim = "aaaaabbbbaaaacccbbbHelloWorldaaaaccccaabbbaac";
	set = "abc";
	printf("%s\n", ft_strtrim(to_trim, set));
}
*/