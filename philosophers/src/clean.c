/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:38:03 by sophie            #+#    #+#             */
/*   Updated: 2026/03/31 12:51:44 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	clean_philo(t_philo **philo, int nb)
{
	while (nb >= 0)
	{
		if (philo[nb])
		{
			pthread_mutex_destroy(&philo[nb]->meal_lock);
			free(philo[nb]);
		}
		philo[nb] = NULL;
		nb--;
	}
	free(philo);
}

void    free_global(t_global *global)
{
	int i;

	if (!global)
		return ;
	if (global->philo)
		clean_philo(global->philo, global->nb_philo - 1);
	if (global->forks)
	{
		i = 0;
		while (i < global->nb_philo)
		{
			pthread_mutex_destroy(&global->forks[i]);
			i++;
		}
		free(global->forks);
	}
	pthread_mutex_destroy(&global->meal);
	pthread_mutex_destroy(&global->message);
	pthread_mutex_destroy(&global->death);
	free(global);
}
