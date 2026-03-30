/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:47:38 by sophie            #+#    #+#             */
/*   Updated: 2026/03/30 19:34:31 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int ac, char **av)
{
	t_global	*global;
	int			i;

	i = 0;
	if (!check_args(ac, av))
		return (1);
	global = init_global(ac, av);
	if (start_thread(global) == -1)
		return (-1); // clean up needed?
	meal_monito(global);
	while (i < global->nb_philo)
	{
		join_thread(&global->philo[i]->philo_thread);
		i++;
	}
	free_global(global);
	return (0);
}