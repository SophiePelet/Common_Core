/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:10:18 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/19 17:18:33 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'

typedef struct s_elem
{
	int	collectible;
	int	player;
	int	exit;
}		t_elem;

char	**parse_map(const char *file_path);
int		check_rect(char **map_data);
int		check_walls(char **map);
int		check_walls_middle(char **map);
t_elem	elem_count(char **map);
int		elem_check_counts(t_elem cnt);
int		elem_check(char **map);

#endif