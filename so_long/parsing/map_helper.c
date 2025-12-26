#include "libft.h"
#include "so_long.h"
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

t_map	*map_dimension(char **map)
{
	t_map	*dimensions;

	dimensions = malloc(sizeof(t_map));
	if (!dimensions)
		return (NULL);
	dimensions->height = size_map(map);
	dimensions->width = ft_strlen(map[0]);
	if (dimensions->width != 0 && dimensions->height > INT_MAX
		/ dimensions->width)
		exit(1);
	dimensions->dim = dimensions->width * dimensions->height;
	return (dimensions);
}

char	**dup_map(char **map)
{
	char **dup;
	t_map *map_dim;
	int i;
	int j;

	i = 0;
	j = 0;
	map_dim = map_dimension(map);
	dup = malloc(sizeof(char *) * map_dim->dim);
	while (i < map_dim->height)
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	return (dup);
}