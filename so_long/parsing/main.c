/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:27:05 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/26 20:39:44 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char **map;
	int i;
	char **dup;

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
	dup = dup_map(map);
	if (!flood_fill(dup))
		exit(1);
	while (dup[i])
	{
		ft_printf("%s\n", dup[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}