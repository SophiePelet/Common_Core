/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:00:00 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/05 18:51:59 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_exit(t_map *map)
{
	int	width;
	int	height;

	map->exit.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "textures/exit.xpm",
			&width, &height);
	if (!map->exit.xpm_ptr)
		return (ft_putstr("Failed to load sprite\n"), 0);
	map->exit.width = width;
	map->exit.height = height;
	return (1);
}

int	load_coll(t_map *map)
{
	int	width;
	int	height;

	map->coll.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "textures/cake.xpm",
			&width, &height);
	if (!map->coll.xpm_ptr)
		return (ft_putstr("Failed to load sprite\n"), 0);
	map->coll.width = width;
	map->coll.height = height;
	return (1);
}

int	load_floor_wall(t_map *map)
{
	int	width;
	int	height;

	map->floor.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/floor.xpm", &width, &height);
	if (!map->floor.xpm_ptr)
		return (ft_putstr("Failed to load sprite\n"), 0);
	map->floor.width = width;
	map->floor.height = height;
	map->wall.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "textures/wall.xpm",
			&width, &height);
	if (!map->wall.xpm_ptr)
		return (ft_putstr("Failed to load sprite\n"), 0);
	map->wall.width = width;
	map->wall.height = height;
	return (1);
}

int	load_sprites(t_map *map)
{
	if (load_floor_wall(map) && load_coll(map) && load_player_front(map)
		&& load_player_back(map) && load_player_right(map)
		&& load_player_left(map) && load_exit(map))
		return (1);
	free_image(map);
	return (0);
}
