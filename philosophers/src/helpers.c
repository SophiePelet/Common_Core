/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:49:55 by sopelet           #+#    #+#             */
/*   Updated: 2026/03/30 19:17:13 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	get_time_in_ms(void)
{
    struct timeval	tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int check_stop(t_global *global)
{
    if (!lock_mutex(&global->death))
        return (-1);
    if (global->stop_routine == 1)
    {
        if (!unlock_mutex(&global->death))
            return (-1);
        return (1);
    }
    if (!unlock_mutex(&global->death))
        return (-1);
    return (0);
}

int    set_stop(t_global *global)
{
    if (!lock_mutex(&global->death))
        return (-1);
    if (global->stop_routine == 0)
        global->stop_routine = 1;
    if (!unlock_mutex(&global->death))
        return (-1);
    return (0);
}

int interrupt_sleep(t_global *global, size_t wait)
{
    size_t  start;
    size_t  progress;
    int     stop;

    progress = 0;
    start = get_time_in_ms();
    while (progress < wait)
    {
        stop = check_stop(global);
        if (stop == 1)
            return (0); // return something else when stop == 1? return 1?
        if (stop == -1)
            return (-1);
        usleep(100);
        progress = (get_time_in_ms() - start);
    }
    return (0);
}
