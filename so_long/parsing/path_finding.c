#include "so_long.h"
#include <stdlib.h>

t_pos	*position(char c, char **map)
{
	int		i;
	int		j;
	t_pos	*pos;

	i = 0;
	pos = malloc(sizeof(t_pos));
	if (!pos)
		return (NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				pos->x = j;
				pos->y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	free(pos);
	return (NULL);
}

static void	check_neighbors(t_queue *q, t_visited *v, char **map, t_pos pos)
{
	int	dirs[4][2];
	int	i;
	int	nx;
	int	ny;

	dirs[0][0] = 0;
	dirs[0][1] = -1;
	dirs[1][0] = 0;
	dirs[1][1] = 1;
	dirs[2][0] = -1;
	dirs[2][1] = 0;
	dirs[3][0] = 1;
	dirs[3][1] = 0;
	i = 0;
	while (i < 4)
	{
		nx = pos.x + dirs[i][0];
		ny = pos.y + dirs[i][1];
		if (is_floor(map, nx, ny) && !mark_visited(v, nx, ny))
		{
			add_end(q, nx, ny);
			visited(v, nx, ny);
		}
		i++;
	}
}

//create a free function so that it is less than 25 lines
int	bfs_find_path(char **map, t_pos start, t_pos end)
{
	t_queue		*queue;
	t_map		dims;
	t_visited	*vis;
	int			x;
	int			y;

	if (!map_dimension(map, &dims))
		return (0);
	queue = queue_alloc();
	vis = visited_alloc(dims.height, dims.width);
	if (!queue || !vis)
		return (0);
	add_end(queue, start.x, start.y);
	visited(vis, start.x, start.y);
	while (remove_front(queue, &x, &y))
	{
		if (x == end.x && y == end.y)
		{
			free_all(queue);
			free_visited(vis, vis->height);
			return (1);
		}
		check_neighbors(queue, vis, map, (t_pos){x, y});
	}
	free_all(queue);
	free_visited(vis, vis->height);
	return (0);
}

int	is_path_valid(char **map)
{
	t_pos	*player;
	t_pos	*exit;
	int		result;

	player = position(PLAYER, map);
	exit = position(EXIT, map);
	if (!player || !exit)
	{
		free(player);
		free(exit);
		return (0);
	}
	result = bfs_find_path(map, *player, *exit);
	free(player);
	free(exit);
	return (result);
}
