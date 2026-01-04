/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:00:00 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/04 18:35:51 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_exit(t_map *map)
{
	int	width;
	int	height;

	map->exit.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "textures/exit.xpm",
			&width, &height);
	if (!map->exit.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit (1);
	}
	map->exit.width = width;
	map->exit.height = height;
}

void	load_coll(t_map *map)
{
	int	width;
	int	height;

	map->coll.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/cake.xpm", &width, &height);
	if (!map->coll.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit (1);
	}
	map->coll.width = width;
	map->coll.height = height;
}

void	load_floor_wall(t_map *map)
{
	int	width;
	int	height;

	map->floor.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/floor.xpm", &width, &height);
	if (!map->floor.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit (1);
	}
	map->floor.width = width;
	map->floor.height = height;
	map->wall.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "textures/wall.xpm",
			&width, &height);
	if (!map->wall.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit (1);
	}
	map->wall.width = width;
	map->wall.height = height;
}

void	load_sprites(t_map *map)
{
	load_floor_wall(map);
	load_coll(map);
	load_player_front(map);
	load_player_back(map);
	load_player_right(map);
	load_player_left(map);
	load_exit(map);
}
