/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:38:03 by sophie            #+#    #+#             */
/*   Updated: 2026/03/26 14:15:03 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void    free_global(t_global *global)
{
    int i;

    if (!global)
        return ;
    if (global->philo)
    {
        i = 0;
        while (i < global->nb_philo)
        {
            if (global->philo[i])
            {
                pthread_mutex_destroy(&global->philo[i]->meal_lock);
                free(global->philo[i]);
            }
            i++;
        }
        free(global->philo);
    }
    if (global->forks)
    {
        i = 0;
        while (i < global->nb_philo)
        {
            pthread_mutex_destroy(&global->forks[i]);
            i++;
        }
        free(global->forks);
        pthread_mutex_destroy(&global->meal);
        pthread_mutex_destroy(&global->message);
        pthread_mutex_destroy(&global->death);
    }
    free(global);
}
