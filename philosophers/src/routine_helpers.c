/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:39:25 by sopelet           #+#    #+#             */
/*   Updated: 2026/03/31 23:10:41 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_and_forks(t_philo *philo, int *has_forks)
{
	int	stop;
	int	res;

	stop = check_stop(philo->global);
	if (stop == 1)
		return (0);
	if (stop == -1)
	{
		set_stop(philo->global);
		return (0);
	}
	res = take_forks(philo);
	if (res == -1)
	{
		set_stop(philo->global);
		return (0);
	}
	*has_forks = 1;
	return (1);
}

void	single_philo(t_philo *philo, int *has_forks)
{
	if (!lock_mutex(&philo->meal_lock))
	{
		set_stop(philo->global);
		return ;
	}
	philo->last_meal = get_time_in_ms();
	if (!unlock_mutex(&philo->meal_lock))
	{
		set_stop(philo->global);
		return ;
	}
	if (interrupt_sleep(philo->global, philo->global->time_to_die) == -1)
	{
		set_stop(philo->global);
		return ;
	}
	drop_forks(philo);
	*has_forks = 0;
	return ;
}

int	philo_eat(t_philo *philo)
{
	if (!lock_mutex(&philo->meal_lock))
	{
		set_stop(philo->global);
		return (0);
	}
	philo->last_meal = get_time_in_ms();
	if (!unlock_mutex(&philo->meal_lock))
	{
		set_stop(philo->global);
		return (0);
	}
	if (print_messages(philo, EAT) == -1)
	{
		set_stop(philo->global);
		return (0);
	}
	if (interrupt_sleep(philo->global, philo->global->time_to_eat) == -1)
	{
		set_stop(philo->global);
		return (0);
	}
	return (1);
}

int	increment_meals(t_philo *philo, int *has_forks)
{
	if (!lock_mutex(&philo->meal_lock))
	{
		set_stop(philo->global);
		return (0);
	}
	philo->nb_meals++;
	if (philo->global->max_meal > 0 && philo->nb_meals >= philo->global->max_meal)
		philo->is_full = 1;
	if (!unlock_mutex(&philo->meal_lock))
	{
		set_stop(philo->global);
		return (0);
	}
	drop_forks(philo);
	*has_forks = 0;
	return (1);
}

int	philo_sleep_think(t_philo *philo)
{
	if (print_messages(philo, SLEEP) == -1)
	{
		set_stop(philo->global);
		return (0);
	}
	if (interrupt_sleep(philo->global, philo->global->time_to_sleep) == -1)
	{
		set_stop(philo->global);
		return (0);
	}
	if (print_messages(philo, THINK) == -1)
	{
		set_stop(philo->global);
		return (0);
	}
	if (philo->global->nb_philo % 2 == 1)
	{
		if (interrupt_sleep(philo->global, philo->global->time_to_eat / 2) == -1)
		{
			set_stop(philo->global);
			return (0);
		}
	}
	return (1);
}

/*
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
				set_stop(philo->global);
				break ;
			}
			philo->last_meal = get_time_in_ms();
			if (!unlock_mutex(&philo->meal_lock))
			{
				set_stop(philo->global);
				break ;
			}
			interrupt_sleep(philo->global, philo->global->time_to_eat);
			drop_forks(philo);
			has_forks = 0;
			break ;
		}
		if (!lock_mutex(&philo->meal_lock))
		{
			set_stop(philo->global);
			break ;
		}
		philo->last_meal = get_time_in_ms();
		if (!unlock_mutex(&philo->meal_lock))
		{
			set_stop(philo->global);
			break ;
		}
		if (print_messages(philo, EAT) == -1)
		{
			set_stop(philo->global);
			break ;
		}
		if (interrupt_sleep(philo->global, philo->global->time_to_eat) == -1)
		{
			set_stop(philo->global);
			break ;
		}
		if (!lock_mutex(&philo->meal_lock))
		{
			set_stop(philo->global);
			break ;
		}
		philo->nb_meals++;
		if (philo->global->max_meal > 0 && philo->nb_meals >= philo->global->max_meal)
			philo->is_full = 1;
		if (!unlock_mutex(&philo->meal_lock))
		{
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
	if (has_forks)
		drop_forks(philo);
	return (NULL);
}
*/