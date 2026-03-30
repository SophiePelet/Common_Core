/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:55:32 by sophie            #+#    #+#             */
/*   Updated: 2026/03/30 18:56:54 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int    start_thread(t_global *global)
{
	int i;
	int j;

	i = 0;
	global->start = get_time_in_ms();
	while (i < global->nb_philo)
	{
		if (!lock_mutex(&global->philo[i]->meal_lock))
			return (-1); // clean up needed?
		global->philo[i]->last_meal = global->start;
		if (!unlock_mutex(&global->philo[i]->meal_lock))
			return (-1); // clean up needed?
		if (!create_thread(&global->philo[i]->philo_thread, routine,
				global->philo[i]))
		{
			j = i - 1;
			set_stop(global);
			while (j >= 0)
			{
				join_thread(&global->philo[j]->philo_thread);
				j--;
			}
			return (-1); // clean up needed?
		}
		i++;
	}
	return (0);
}
