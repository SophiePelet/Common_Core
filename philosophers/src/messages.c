/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:32:22 by sophie            #+#    #+#             */
/*   Updated: 2026/03/26 18:49:55 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	is_printable(t_philo *philo, char *print)
{
	int	printable;

	printable = 0;
	if (philo->global->stop_routine == 0 || ft_strcmp(print, DEAD) == 0)
		printable = 1;
	return (printable);
}

int print_messages(t_philo *philo, char *print)
{
	size_t	time;
	int		printable;

	if (!lock_mutex(&philo->global->death))
		return (-1);
	printable = is_printable(philo, print);
	if (!lock_mutex(&philo->global->message))
	{
		unlock_mutex(&philo->global->death);
		return (-1);
	}
	if (printable)
	{
		time = get_time_in_ms() - philo->global->start;
		printf("%zu %d %s\n", time, philo->id, print);
	}
	if (!unlock_mutex(&philo->global->message))
	{
		unlock_mutex(&philo->global->death);
		return (-1);
	}
	if (!unlock_mutex(&philo->global->death))
		return (-1);
	return (0);
}
