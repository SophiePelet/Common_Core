/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 23:12:05 by sophie            #+#    #+#             */
/*   Updated: 2026/03/31 23:12:32 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	philo_steps(t_philo *philo, int *has_forks)
{ 
	if (!philo_eat(philo))
		return (0);
	if (!increment_meals(philo, has_forks))
		return (0);
	if (!philo_sleep_think(philo))
		return (0);
	return (1);
}

void    *routine(void *arg)
{
	t_philo *philo;
	int     has_forks;

	philo = (t_philo *)arg;
	if (!philo || !philo->global)
		return (NULL);
	has_forks = 0;
	if (philo->id % 2 == 0)
		interrupt_sleep(philo->global, philo->global->time_to_eat / 2);
	while (1)
	{
		if (!check_and_forks(philo, &has_forks))
			break ;
		if (philo->global->nb_philo == 1)
		{
			single_philo(philo, &has_forks);
			break ;
		}
		if (!philo_steps(philo, &has_forks))
			break ;
	}
	if (has_forks)
		drop_forks(philo);
	return (NULL);
}
