/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:00:00 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/30 16:59:59 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player(t_map *map)
{
	int	width;
	int	height;

	map->gamer_front.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_front.xpm", &width, &height);
	map->gamer_front.width = width;
	map->gamer_front.height = height;
	map->gamer_back.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_back.xpm", &width, &height);
	map->gamer_back.width = width;
	map->gamer_back.height = height;
	map->gamer_left.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_left.xpm", &width, &height);
	map->gamer_left.width = width;
	map->gamer_left.height = height;
	map->gamer_right.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_right.xpm", &width, &height);
	map->gamer_right.width = width;
	map->gamer_right.height = height;
}


void	load_exit(t_map *map)
{
	int	width;
	int	height;

	map->exit.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "textures/door.xpm",
			&width, &height);
	map->exit.width = width;
	map->exit.height = height;
}

void	load_coll(t_map *map)
{
	int	width;
	int	height;

	map->coll.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/cake.xpm", &width, &height);
	map->coll.width = width;
	map->coll.height = height;
}

void	load_floor_wall(t_map *map)
{
	int width;
	int height;

	map->floor.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/floor.xpm", &width, &height);
	map->floor.width = width;
	map->floor.height = height;
	map->wall.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "textures/wall.xpm",
			&width, &height);
	map->wall.width = width;
	map->wall.height = height;
}

void	load_sprites(t_map *map)
{
	load_floor_wall(map);
	load_coll(map);
	load_player(map);
	load_exit(map);
}