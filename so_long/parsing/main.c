/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:27:05 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/22 16:52:12 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char **map;
	int i;

	i = 0;
	map = parse_map("map.ber");
	if (!map)
	{
		ft_putstr("Failed to parse map\n");
		return (1);
	}
	if (!check_rect(map))
		exit(1);
	if (!check_walls(map))
		exit(1);
	if (!check_walls_middle(map))
		exit(1);
	if (!elem_check(map))
		exit(1);
	if (!is_path_valid(map))
	{
		ft_putstr("No valid path");
		exit(1);
	}
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	while (i > 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	return (0);
}