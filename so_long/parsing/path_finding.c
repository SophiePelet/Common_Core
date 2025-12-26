#include "libft.h"
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

t_elem	fill(char **tab, t_map *size, int row, int col)
{
	static t_elem	elements;

	if (tab == NULL)
	{
		elements.collectible = 0;
		elements.exit = 0;
		return (elements);
	}
	if (row < 0 || col < 0 || row >= size->height || col >= size->width)
		return (elements);
	if (tab[row][col] == 'V' || tab[row][col] == WALL)
		return (elements);
	if (tab[row][col] == COLLECTIBLE)
		elements.collectible++;
	if (tab[row][col] == EXIT)
		elements.exit++;
	tab[row][col] = 'V';
	fill(tab, size, row - 1, col);
	fill(tab, size, row + 1, col);
	fill(tab, size, row, col - 1);
	fill(tab, size, row, col + 1);
	return (elements);
}

int	flood_fill(char **tab)
{
	t_map	*size;
	t_pos	*start_pos;
	t_elem	cnt;
	t_elem	elements;

	size = map_dimension(tab);
	if (!size)
		return (0);
	start_pos = position(PLAYER, tab);
	cnt = elem_count(tab);
	fill(NULL, NULL, 0, 0);
	elements = fill(tab, size, start_pos->y, start_pos->x);
	free(start_pos);
	free(size);
	if (cnt.collectible != elements.collectible || cnt.exit != 1)
	{
		ft_putstr("Couldn't find a valid path");
		return (0);
	}
	return (1);
}
