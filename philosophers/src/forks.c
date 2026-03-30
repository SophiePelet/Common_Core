/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:02:58 by sophie            #+#    #+#             */
/*   Updated: 2026/03/27 14:12:48 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void drop_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        unlock_mutex(philo->left_f);
        unlock_mutex(philo->right_f);
        return ;
    }
    else
    {
        unlock_mutex(philo->right_f);
        unlock_mutex(philo->left_f);
        return ;
    }
}

int pick_even(t_philo *philo)
{
    if (!lock_mutex(philo->right_f))
        return (-1);
    if (print_messages(philo, FORK) == -1)
    {
        unlock_mutex(philo->right_f);
        return (-1);
    }
    if (!lock_mutex(philo->left_f))
    {
        unlock_mutex(philo->right_f);
        return (-1);
    }
    if (print_messages(philo, FORK) == -1)
    {
        drop_forks(philo);
        return (-1);
    }
    return (0);
}

int pick_odd(t_philo *philo)
{
    if (!lock_mutex(philo->left_f))
        return (-1);
    if (print_messages(philo, FORK) == -1)
    {
        unlock_mutex(philo->left_f);
        return (-1);
    }
    if (!lock_mutex(philo->right_f))
    {
        unlock_mutex(philo->left_f);
        return (-1);
    }
    if (print_messages(philo, FORK) == -1)
    {
        drop_forks(philo);
        return (-1);
    }
    return (0);
}

int take_forks(t_philo *philo)
{
    if (philo->global->nb_philo == 1)
    {
        if (!lock_mutex(philo->right_f))
            return (-1);
        if (print_messages(philo, FORK) == -1)
        {
            unlock_mutex(philo->right_f);
            return (-1);
        }
        return (0);
    }
    if (philo->id % 2 == 0)
    {
        if (pick_even(philo) == -1)
            return (-1);
    }
    else
    {
        if (pick_odd(philo) == -1)
            return (-1);
    }
    return (0);
}
