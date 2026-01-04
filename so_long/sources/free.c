/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:14:00 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/04 18:35:17 by sopelet          ###   ########.fr       */
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
		free(dup[i++]);
	free(dup);
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

void	free_image(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->exit.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->floor.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->gamer_back.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->gamer_front.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->gamer_right.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->gamer_left.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->wall.xpm_ptr);
	mlx_destroy_image(map->mlx_ptr, map->coll.xpm_ptr);
}

void	free_all(t_map *map)
{
	free_image(map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free_dup(map->grid);
	free(map->mlx_ptr);
	free(map);
}
