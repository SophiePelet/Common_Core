/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:34:27 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/05 17:55:40 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

size_t	count_map_line(int fd)
{
	size_t	nb_line;
	char	*line;

	nb_line = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, 0);
		nb_line++;
	}
	return (nb_line);
}

t_map_dim	map_dimension(char **map)
{
	t_map_dim	dimensions;

	dimensions.height = size_map(map);
	dimensions.width = ft_strlen(map[0]);
	if (dimensions.width != 0 && dimensions.height > INT_MAX / dimensions.width)
		exit(1);
	dimensions.dim = dimensions.width * dimensions.height;
	return (dimensions);
}

char	**dup_map(char **map)
{
	char		**dup;
	t_map_dim	map_dim;
	int			i;

	i = 0;
	map_dim = map_dimension(map);
	dup = malloc(sizeof(char *) * (map_dim.height + 1));
	if (!dup)
		return (NULL);
	while (i < map_dim.height)
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

t_map	*build_map(char **map, char **dup, t_map_dim size, t_elem counts)
{
	t_map		*map_struct;
	t_player	player;

	player = position(PLAYER, map);
	if (player.x < 0 || player.y < 0)
		exit(1);
	if (!flood_fill(dup, size, player, counts))
	{
		free_dup(map);
		exit(1);
	}
	map_struct = malloc(sizeof(t_map));
	if (!map_struct)
	{
		free_dup(map);
		exit(1);
	}
	map_struct->grid = map;
	map_struct->size = size;
	map_struct->elem_counts = counts;
	player.player_sprite = P_FRONT;
	map_struct->player = player;
	map_struct->moves = 0;
	return (map_struct);
}

int	check_ber(const char *file_path)
{
	size_t	len;

	if (!file_path)
		return (0);
	len = ft_strlen(file_path);
	if (len < 4 || ft_strncmp(file_path + len - 4, ".ber", 4) != 0)
	{
		ft_putstr("Error\nWrong extension for the map\n");
		return (0);
	}
	return (1);
}
