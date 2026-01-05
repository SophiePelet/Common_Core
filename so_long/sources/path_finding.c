/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:35:58 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/05 17:55:55 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

t_player	position(char c, char **map)
{
	int			i;
	int			j;
	t_player	pos;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_elem	fill(char **tab, t_map_dim size, int row, int col)
{
	static t_elem	elements;

	if (tab == NULL)
	{
		elements.collectible = 0;
		elements.exit = 0;
		return (elements);
	}
	if (row < 0 || col < 0 || row >= size.height || col >= size.width)
		return (elements);
	if (tab[row][col] == 'V' || tab[row][col] == WALL || tab[row][col] == EXIT)
	{
		if (tab[row][col] == EXIT)
			elements.exit = 1;
		return (elements);
	}
	if (tab[row][col] == COLLECTIBLE)
		elements.collectible++;
	tab[row][col] = 'V';
	fill(tab, size, row - 1, col);
	fill(tab, size, row + 1, col);
	fill(tab, size, row, col - 1);
	fill(tab, size, row, col + 1);
	return (elements);
}

int	flood_fill(char **tab, t_map_dim size, t_player start, t_elem expected)
{
	t_elem	elements;

	fill(NULL, size, 0, 0);
	elements = fill(tab, size, start.y, start.x);
	if (expected.collectible != elements.collectible || elements.exit != 1)
	{
		ft_putstr("Couldn't find a valid path");
		free_dup(tab);
		return (0);
	}
	return (1);
}
