/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:10:18 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/26 20:37:19 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdlib.h>

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'

typedef struct s_elem
{
	int	collectible;
	int	player;
	int	exit;
}		t_elem;

typedef struct s_map
{
	int	height;
	int	width;
	int	dim;
}		t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

char	**parse_map(const char *file_path);
int		check_rect(char **map_data);
int		check_walls(char **map);
int		check_walls_middle(char **map);
t_elem	elem_count(char **map);
int		elem_check_counts(t_elem cnt);
int		elem_check(char **map);
t_pos	*position(char c, char **map);
size_t	count_map_line(int fd);
t_map	*map_dimension(char **map);
size_t	size_map(char **map_data);
t_elem	fill(char **tab, t_map *size, int row, int col);
int		flood_fill(char **tab);
char	**dup_map(char **map);

#endif