/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:07:26 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/05 17:56:04 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	**read_map(int fd, int nb_line)
{
	char	**map_data;
	int		i;
	char	*line;

	map_data = malloc(sizeof(char *) * (nb_line + 1));
	if (!map_data)
		return (NULL);
	i = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		map_data[i++] = line;
		line = get_next_line(fd, 0);
		if (i > nb_line)
			return (free(line), free_map(map_data, i), NULL);
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
	map_data[i] = NULL;
	return (map_data);
}

static int	count_lines(const char *file_path, int *nb_line)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\nCouldn't open file\n");
		return (-1);
	}
	*nb_line = count_map_line(fd);
	close(fd);
	if (*nb_line == 0)
	{
		ft_putstr("Error\nEmpty file or not readable\n");
		return (-1);
	}
	return (0);
}

static char	**open_clean_map(const char *file_path, int nb_line)
{
	int		fd;
	char	**map;
	char	**clean_map;

	fd = open(file_path, O_RDONLY);
	map = read_map(fd, nb_line);
	close(fd);
	get_next_line(fd, 1);
	if (!map)
	{
		ft_putstr("Error reading map\n");
		return (NULL);
	}
	clean_map = remove_line_break(map);
	return (clean_map);
}

char	**parse_map(const char *file_path)
{
	int	nb_line;

	if (!check_ber(file_path))
		exit(1);
	if (count_lines(file_path, &nb_line) < 0)
		exit(1);
	return (open_clean_map(file_path, nb_line));
}
