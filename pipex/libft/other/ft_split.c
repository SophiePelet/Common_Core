/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:42:43 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/03 17:53:21 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	cnt_words(const char *str, char sep)
{
	int	trigger;
	int	cnt;

	trigger = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (*str != sep && trigger == 0)
		{
			trigger = 1;
			cnt++;
		}
		if (*str == sep)
			trigger = 0;
		str++;
	}
	return (cnt);
}

static void	*free_contents(const char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free((char *)strs[i]);
		i++;
	}
	return (NULL);
}

static char	**aled(char **split, const char *s, char c)
{
	int	i;
	int	j;
	int	word_start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		word_start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > word_start)
		{
			split[j] = ft_substr(s, word_start, (i - word_start));
			if (!split[j])
				return (free_contents((const char **)split, j));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char *) * (cnt_words(s, c) + 1));
	if (!new)
		return (NULL);
	if (aled(new, s, c) == NULL)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

/* #include <stdio.h>

int	main(void)
{
	char *str;
	char sep;
	char **split_str;
	int i;

	i = 0;
	str = "helloz\nhizzzz\nopz   ";
	sep = '\n';
	split_str = ft_split(str, sep);
	while (split_str[i] != NULL)
	{
		printf("%s\n", split_str[i]);
		i++;
	}
	free(split_str);
	return (0);
} */