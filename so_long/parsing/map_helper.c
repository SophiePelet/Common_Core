#include "so_long.h"
#include "libft.h"
#include <stdio.h>

size_t	count_map_line(int fd)
{
	size_t	nb_line;
	char	*line;

	nb_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		nb_line++;
	}
	return (nb_line);
}

int	map_dimension(char **map, t_map *dimensions)
{
	dimensions->height = size_map(map);
	dimensions->width = ft_strlen(map[0]);
	if (dimensions->width != 0 && dimensions->height > SIZE_MAX
		/ dimensions->width)
		return (0);
	dimensions->dim = dimensions->width * dimensions->height;
	return (1);
}

int	is_floor(char **map, int x, int y)
{
	if (map[y][x] == WALL)
		return (0);
	return (1);
}
