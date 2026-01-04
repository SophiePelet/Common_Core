/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:10:18 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/04 18:19:10 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdlib.h>

// Elements
# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'

// Keys
# define UP "119"
# define DOWN "115"
# define RIGHT "100"
# define LEFT "97"
# define ESC "65307"

// Window
# define NAME "SO_LONG"
# define SPRITE_SIZE 64
# define P_FRONT 0
# define P_BACK 1
# define P_RIGHT 2
# define P_LEFT 3

typedef struct s_elem
{
	int			collectible;
	int			player;
	int			exit;
}				t_elem;

typedef struct s_map_dim
{
	int			height;
	int			width;
	int			dim;
}				t_map_dim;

typedef struct s_player
{
	int			x;
	int			y;
	int			player_sprite;
}				t_player;

typedef struct s_img
{
	void		*xpm_ptr;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	char		**grid;
	t_map_dim	size;
	t_player	player;
	t_elem		elem_counts;
	int			moves;
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		coll;
	t_img		gamer_front;
	t_img		gamer_back;
	t_img		gamer_right;
	t_img		gamer_left;
	t_img		wall;
	t_img		exit;
	t_img		floor;
}				t_map;

// Parsing and path finding
char			**parse_map(const char *file_path);
int				check_ber(const char *file_path);
int				check_rect(char **map_data);
int				check_walls(char **map);
int				check_walls_middle(char **map);
t_elem			elem_count(char **map);
int				elem_check_counts(t_elem cnt);
int				elem_check(char **map);
t_player		position(char c, char **map);
size_t			count_map_line(int fd);
t_map_dim		map_dimension(char **map);
size_t			size_map(char **map_data);
t_elem			fill(char **tab, t_map_dim size, int row, int col);
int				flood_fill(char **tab, t_map_dim size, t_player start,
					t_elem expected);
char			**dup_map(char **map);
t_map			*get_map(const char *path);
t_map			*build_map(char **map, char **dup, t_map_dim size,
					t_elem counts);

// Freeing
char			**free_map(char **map, int index);
void			free_dup(char **map);
void			free_all(t_map *map);

// Key handling and map rendering
int				handle_key(int key, t_map *map);
int				handle_closing(t_map *map);
void			render_grid(t_map *map, int y, int x);
void			render_map(t_map *map);
void			render_fix(t_map *map, int y, int x);
t_img			player_sprite(t_map *map);
void			put_sprite(t_map *map, t_img image, int y, int x);
void			nb_moves(t_map *map);

// Loading sprites
void			load_floor_wall(t_map *map);
void			load_coll(t_map *map);
void			load_player_front(t_map *map);
void			load_player_back(t_map *map);
void			load_player_right(t_map *map);
void			load_player_left(t_map *map);
void			load_exit(t_map *map);
void			load_sprites(t_map *map);

#endif