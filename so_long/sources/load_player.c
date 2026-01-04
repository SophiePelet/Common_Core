/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:32:44 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/04 18:33:08 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_front(t_map *map)
{
	int	width;
	int	height;

	map->gamer_front.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_front.xpm", &width, &height);
	if (!map->gamer_front.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit(1);
	}
	map->gamer_front.width = width;
	map->gamer_front.height = height;
}

void	load_player_back(t_map *map)
{
	int	width;
	int	height;

	map->gamer_back.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_back.xpm", &width, &height);
	if (!map->gamer_back.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit(1);
	}
	map->gamer_back.width = width;
	map->gamer_back.height = height;
}

void	load_player_right(t_map *map)
{
	int	width;
	int	height;

	map->gamer_right.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_right.xpm", &width, &height);
	if (!map->gamer_right.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit(1);
	}
	map->gamer_right.width = width;
	map->gamer_right.height = height;
}

void	load_player_left(t_map *map)
{
	int	width;
	int	height;

	map->gamer_left.xpm_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"textures/girl_left.xpm", &width, &height);
	if (!map->gamer_left.xpm_ptr)
	{
		ft_putstr("Failed to load sprite\n");
		exit(1);
	}
	map->gamer_left.width = width;
	map->gamer_left.height = height;
}
