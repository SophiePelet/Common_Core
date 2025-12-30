#include "so_long.h"

void	put_sprite(t_map *map, t_img image, int y, int x)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, image.xpm_ptr,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}

t_img	player_sprite(t_map *map)
{
	if (map->player.player_sprite == 0)
		return (map->gamer_front);
	else if (map->player.player_sprite == 1)
		return (map->gamer_back);
	else if (map->player.player_sprite == 2)
		return (map->gamer_right);
	else if (map->player.player_sprite == 3)
		return (map->gamer_left);
	return (map->gamer_front);
}

void	render_grid(t_map *map, int y, int x)
{
	char	current;

	current = map->grid[y][x];
	put_sprite(map, map->floor, y, x);
	if (current == WALL)
		put_sprite(map, map->wall, y, x);
	else if (current == COLLECTIBLE)
		put_sprite(map, map->coll, y, x);
	else if (current == EXIT)
		put_sprite(map, map->exit, y, x);
	else if (current == PLAYER)
		put_sprite(map, player_sprite(map), y, x);
}

void	render_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->size.height)
	{
		x = 0;
		while (x < map->size.width)
		{
			render_grid(map, y, x);
			x++;
		}
		y++;
	}
}

void	render_fix(t_map *map, int y, int x)
{
	char	current;

	current = map->grid[y][x];
	if (current == FLOOR)
		put_sprite(map, map->floor, y, x);
	else if (current == COLLECTIBLE)
		put_sprite(map, map->coll, y, x);
	else if (current == PLAYER)
		put_sprite(map, player_sprite(map), y, x);
	else
		return ;
}