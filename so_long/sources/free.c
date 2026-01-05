/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:14:00 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/05 19:35:49 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_dup(char **dup)
{
	int	i;

	i = 0;
	if (!dup)
		return ;
	while (dup[i])
	{
		free(dup[i]);
		dup[i] = NULL;
		i++;
	}
	free(dup);
	dup = NULL;
}

char	**free_map(char **map, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

static void	free_player(t_map *map)
{
	if (map->gamer_back.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->gamer_back.xpm_ptr);
		map->gamer_back.xpm_ptr = NULL;
	}
	if (map->gamer_front.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->gamer_front.xpm_ptr);
		map->gamer_front.xpm_ptr = NULL;
	}
	if (map->gamer_right.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->gamer_right.xpm_ptr);
		map->gamer_right.xpm_ptr = NULL;
	}
	if (map->gamer_left.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->gamer_left.xpm_ptr);
		map->gamer_left.xpm_ptr = NULL;
	}
}

void	free_image(t_map *map)
{
	if (map->wall.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->wall.xpm_ptr);
		map->wall.xpm_ptr = NULL;
	}
	if (map->floor.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->floor.xpm_ptr);
		map->floor.xpm_ptr = NULL;
	}
	if (map->exit.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->exit.xpm_ptr);
		map->exit.xpm_ptr = NULL;
	}
	if (map->coll.xpm_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, map->coll.xpm_ptr);
		map->coll.xpm_ptr = NULL;
	}
	free_player(map);
}

void	free_all(t_map *map)
{
	if (!map)
		return ;
	free_image(map);
	if (map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (map->mlx_ptr)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	free_dup(map->grid);
	free(map);
}
