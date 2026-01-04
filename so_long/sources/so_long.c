/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:27:05 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/02 18:28:16 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>

t_map	*get_map(const char *path)
{
	char		**map;
	char		**dup;
	t_map		*map_struct;
	t_map_dim	size;
	t_elem		counts;

	map = parse_map(path);
	if (!check_rect(map) || !check_walls(map) || !check_walls_middle(map)
		|| !elem_check(map))
		exit(1);
	size = map_dimension(map);
	counts = elem_count(map);
	dup = dup_map(map);
	if (!dup)
		exit(1);
	map_struct = build_map(map, dup, size, counts);
	free_dup(dup);
	return (map_struct);
}

void	nb_moves(t_map *map)
{
	char	*moves;
	char	*steps;

	put_sprite(map, map->wall, 0, 0);
	put_sprite(map, map->wall, 0, 1);
	moves = ft_itoa(map->moves);
	steps = ft_strjoin("Steps : ", moves);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0xcb8dc0ff, steps);
	free(moves);
	free(steps);
}

int	main(int ac, char **av)
{
	t_map	*map;
	int		win_width;
	int		win_height;

	if (ac == 2)
	{
		map = get_map(av[1]);
		win_width = map->size.width * SPRITE_SIZE;
		win_height = map->size.height * SPRITE_SIZE;
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, win_width, win_height,
				NAME);
		load_sprites(map);
		render_map(map);
		nb_moves(map);
		mlx_hook(map->win_ptr, 2, (1L << 0), handle_key, map);
		mlx_loop(map->mlx_ptr);
	}
	return (0);
}
