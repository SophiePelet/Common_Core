/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:14:00 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/30 17:48:22 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_dup(char **dup)
{
	int	i;

	i = 0;
	if (!dup)
		return ;
	while (dup[i])
		free(dup[i++]);
	free(dup);
}

char	**free_map(char **map, int index)
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