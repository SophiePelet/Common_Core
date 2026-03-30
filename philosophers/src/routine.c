/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:39:25 by sopelet           #+#    #+#             */
/*   Updated: 2026/03/30 22:54:18 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void    *routine(void *arg)
{
	t_philo *philo;
	int     stop;
	int     res;
	int     has_forks;

	philo = (t_philo *)arg;
	if (!philo || !philo->global)
		return (NULL);
	has_forks = 0;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		stop = check_stop(philo->global);
		if (stop == 1)
			break ;
		if (stop == -1)
		{
			set_stop(philo->global);
			break ;
		}
		res = take_forks(philo);
		if (res == -1)
		{
			set_stop(philo->global);
			break;
		}
		has_forks = 1;
		if (philo->global->nb_philo == 1)
		{
			if (!lock_mutex(&philo->meal_lock))
			{
				drop_forks(philo);
				set_stop(philo->global);
				break ;
			}
			philo->last_meal = get_time_in_ms();
			if (!unlock_mutex(&philo->meal_lock))
			{
				drop_forks(philo);
				set_stop(philo->global);
				break ;
			}
			interrupt_sleep(philo->global, philo->global->time_to_eat);
			drop_forks(philo);
			break ;
		}
		if (!lock_mutex(&philo->meal_lock))
		{
			drop_forks(philo);
			set_stop(philo->global);
			break ;
		}
		philo->last_meal = get_time_in_ms();
		if (!unlock_mutex(&philo->meal_lock))
		{
			drop_forks(philo);
			set_stop(philo->global);
			break ;
		}
		if (print_messages(philo, EAT) == -1)
		{
			drop_forks(philo);
			set_stop(philo->global);
			break ;
		}
		if (interrupt_sleep(philo->global, philo->global->time_to_eat) == -1)
		{
			drop_forks(philo);
			set_stop(philo->global);
			break ;
		}
		if (!lock_mutex(&philo->meal_lock))
		{
			drop_forks(philo);
			set_stop(philo->global);
			break ;
		}
		philo->nb_meals++;
		if (philo->global->max_meal > 0 && philo->nb_meals >= philo->global->max_meal)
			philo->is_full = 1;
		if (!unlock_mutex(&philo->meal_lock))
		{
			drop_forks(philo);
			set_stop(philo->global);
			break ;
		}
		drop_forks(philo);
		has_forks = 0;
		if (print_messages(philo, SLEEP) == -1)
		{
			set_stop(philo->global);
			break ;
		}
		if (interrupt_sleep(philo->global, philo->global->time_to_sleep) == -1)
		{
			set_stop(philo->global);
			break ;
		}
		if (print_messages(philo, THINK) == -1)
		{
			set_stop(philo->global);
			break ;
		}
	}
	if (has_forks) // add a field to the struct to check this?
		drop_forks(philo);
	return (NULL);
}
