/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:12:22 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/05 18:59:30 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_elem	elem_count(char **map)
{
	t_elem	cnt;
	int		i;
	int		j;

	i = 0;
	cnt.collectible = 0;
	cnt.exit = 0;
	cnt.player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == COLLECTIBLE)
				cnt.collectible++;
			if (map[i][j] == PLAYER)
				cnt.player++;
			if (map[i][j] == EXIT)
				cnt.exit++;
			j++;
		}
		i++;
	}
	return (cnt);
}

int	elem_check_counts(t_elem cnt)
{
	if (cnt.collectible < 1 || cnt.exit != 1 || cnt.player != 1)
	{
		ft_putstr("Error\nWrong number of elements\n");
		return (0);
	}
	return (1);
}

int	elem_check(char **map)
{
	t_elem	cnt;

	cnt = elem_count(map);
	return (elem_check_counts(cnt));
}

int	check_ber(const char *file_path)
{
	size_t	len;

	if (!file_path)
		return (0);
	len = ft_strlen(file_path);
	if (len < 4 || ft_strncmp(file_path + len - 4, ".ber", 4) != 0)
	{
		ft_putstr("Error\nWrong extension for the map\n");
		return (0);
	}
	return (1);
}
