/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:46:36 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/05 20:06:45 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rect(char **map_data)
{
	int		i;
	size_t	line_len;

	i = 0;
	line_len = ft_strlen(map_data[i]);
	i++;
	while (map_data[i])
	{
		if (ft_strlen(map_data[i]) != line_len)
		{
			ft_putstr("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

size_t	size_map(char **map_data)
{
	size_t	i;

	i = 0;
	while (map_data[i])
		i++;
	return (i);
}

int	check_walls(char **map)
{
	size_t	j;
	size_t	size;

	j = 0;
	size = size_map(map);
	while (map[0][j] != '\0')
	{
		if (map[0][j] != WALL)
		{
			ft_putstr("Error\nMap is not surrended by walls\n");
			return (0);
		}
		j++;
	}
	j = 0;
	while (map[size - 1][j] != '\0')
	{
		if (map[size - 1][j] != WALL)
		{
			ft_putstr("Error\nMap is not surrended by walls");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_walls_middle(char **map)
{
	size_t	i;
	size_t	line_len;
	size_t	size;

	i = 1;
	size = size_map(map);
	while (i < (size - 1))
	{
		line_len = ft_strlen(map[i]);
		if (map[i][0] != WALL || map[i][line_len - 1] != WALL)
		{
			ft_putstr("Error\nMap is not surrended by walls");
			return (0);
		}
		i++;
	}
	return (1);
}
