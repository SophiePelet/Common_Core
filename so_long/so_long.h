/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:10:18 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/22 16:50:33 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
#include <stdlib.h>

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define SIZE_MAX __SIZE_MAX__

typedef struct s_elem
{
	int				collectible;
	int				player;
	int				exit;
}					t_elem;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef struct s_queue
{
	t_node			*head;
	t_node			*end;
	int				size;
}					t_queue;

typedef struct s_visited
{
	int				**coor;
	int				height;
	int				width;
}					t_visited;

typedef struct s_map
{
	size_t			height;
	size_t			width;
	size_t			dim;
}					t_map;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

char				**parse_map(const char *file_path);
int					check_rect(char **map_data);
int					check_walls(char **map);
int					check_walls_middle(char **map);
t_elem				elem_count(char **map);
int					elem_check_counts(t_elem cnt);
int					elem_check(char **map);
t_pos				*position(char c, char **map);
size_t				count_map_line(int fd);
int					is_floor(char **map, int x, int y);
int					mark_visited(t_visited *vis, int x, int y);
int					map_dimension(char **map, t_map *dimensions);
t_queue				*queue_alloc(void);
int					add_end(t_queue *queue, int x, int y);
int					remove_front(t_queue *queue, int *x, int *y);
void				free_all(t_queue *queue);
t_visited			*visited_alloc(size_t height, size_t width);
void				visited(t_visited *v, int x, int y);
void				*free_visited(t_visited *vis, int i);
int					bfs_find_path(char **map, t_pos start, t_pos end);
int					is_path_valid(char **map);
size_t				size_map(char **map_data);
t_visited			*visited_alloc(size_t height, size_t width);

#endif