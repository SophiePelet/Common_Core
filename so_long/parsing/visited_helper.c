#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

void	*free_visited(t_visited *vis, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(vis->coor[j]);
		j++;
	}
	free(vis->coor);
	free(vis);
	return (NULL);
}

t_visited	*visited_alloc(size_t height, size_t width)
{
	t_visited	*visited;
	size_t		i;

	i = 0;
	visited = malloc(sizeof(t_visited));
	if (!visited)
		return (NULL);
	visited->height = height;
	visited->width = width;
	visited->coor = malloc(sizeof(int *) * height);
	if (!visited->coor)
	{
		free(visited);
		return (NULL);
	}
	while (i < height)
	{
		visited->coor[i] = ft_calloc(width, sizeof(int));
		if (!visited->coor[i])
			return (free_visited(visited, i));
		i++;
	}
	return (visited);
}

void	visited(t_visited *vis, int x, int y)
{
	if (x >= 0 && x < vis->width && y >= 0 && y < vis->height)
		vis->coor[y][x] = 1;
}

int	mark_visited(t_visited *vis, int x, int y)
{
	if (x < 0 || x >= vis->width || y < 0 || y >= vis->height)
		return (1);
	return (vis->coor[y][x]);
}