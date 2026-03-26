/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:39:25 by sopelet           #+#    #+#             */
/*   Updated: 2026/03/26 19:02:49 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
        unlock_mutex(philo->left_f);
        unlock_mutex(philo->right_f);
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
        unlock_mutex(philo->left_f);
        unlock_mutex(philo->right_f);
        return (-1);
    }
    return (0);
}

int take_forks(t_philo *philo)
{
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

// add release fork function to help clean up