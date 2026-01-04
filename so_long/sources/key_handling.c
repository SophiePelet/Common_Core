/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:12:58 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/02 18:20:30 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player(t_map *map, int next_y, int next_x, int direction)
{
	int	current_y;
	int	current_x;

	current_x = map->player.x;
	current_y = map->player.y;
	map->player.player_sprite = direction;
	if (map->grid[next_y][next_x] == EXIT && map->elem_counts.collectible == 0)
	{
		ft_putstr("VICTORY\n");
		exit(0);
	}
	else if (map->grid[next_y][next_x] == FLOOR
		|| map->grid[next_y][next_x] == COLLECTIBLE)
	{
		if (map->grid[next_y][next_x] == COLLECTIBLE)
			map->elem_counts.collectible--;
		map->grid[current_y][current_x] = FLOOR;
		map->player.y = next_y;
		map->player.x = next_x;
		map->grid[next_y][next_x] = PLAYER;
		map->moves++;
		nb_moves(map);
	}
}

int	handle_key(int key, t_map *map)
{
	int	current_y;
	int	current_x;

	current_y = map->player.y;
	current_x = map->player.x;
	if (key == 119)
		update_player(map, map->player.y - 1, map->player.x, P_BACK);
	else if (key == 115)
		update_player(map, map->player.y + 1, map->player.x, P_FRONT);
	else if (key == 97)
		update_player(map, map->player.y, map->player.x - 1, P_LEFT);
	else if (key == 100)
		update_player(map, map->player.y, map->player.x + 1, P_RIGHT);
	else if (key == 65307)
	{
		ft_putstr("Closing...\n");
		exit(0);
	}
	render_fix(map, current_y, current_x);
	render_fix(map, map->player.y, map->player.x);
	return (0);
}
