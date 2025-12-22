/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:07:26 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/22 15:26:50 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static char	**free_map(char **map, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

char	**read_map(int fd, int nb_line)
{
	char	**map_data;
	int		i;
	char	*line;

	map_data = malloc(sizeof(char *) * (nb_line + 1));
	if (!map_data)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_data[i++] = line;
		line = get_next_line(fd);
		if (i > nb_line)
			return (free_map(map_data, i));
	}
	map_data[i] = NULL;
	return (map_data);
}

static char	**remove_line_break(char **map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data[i])
	{
		j = 0;
		while (map_data[i][j] != '\0' && map_data[i][j] != '\n')
			j++;
		if (map_data[i][j] == '\n')
			map_data[i][j] = '\0';
		i++;
	}
	return (map_data);
}

char	**parse_map(const char *file_path)
{
	int		fd;
	int		nb_line;
	char	**map;
	char	**clean_map;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Couldn't open file");
		exit(1);
	}
	nb_line = count_map_line(fd);
	close(fd);
	fd = open(file_path, O_RDONLY);
	map = read_map(fd, nb_line);
	close(fd);
	if (!map)
	{
		ft_putstr("Error reading map\n");
		return (NULL);
	}
	clean_map = remove_line_break(map);
	return (clean_map);
}
