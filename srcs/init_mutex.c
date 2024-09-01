/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:45:34 by max               #+#    #+#             */
/*   Updated: 2024/09/01 15:12:37 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool init_forks_mutex(t_main_data *main_data)
{
    int i;

    i = 0;

    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        if (pthread_mutex_init(&main_data->shared_data.forks[i], NULL) != 0)
        {
            print_error("Forks mutex initialization failed");
            destroy_partial_forks_mutexs(main_data, i);
            return false;
        }
        i++;
    }
    return true;
}

static bool init_print_mutex(t_main_data *main_data)
{
    if (pthread_mutex_init(&main_data->shared_data.print_mutex, NULL) != 0)
    {
        print_error("Print mutex initialization failed");
        destroy_forks_mutex(main_data);
        clean_forks_and_philosophers(main_data);
        return false;
    }
    return true;
}
static bool init_death_mutex(t_main_data *main_data)
{
    if (pthread_mutex_init(&main_data->shared_data.death, NULL) != 0)
    {
        print_error("Death mutex initialization failed");
        destroy_forks_mutex(main_data);
        destroy_print_mutex(main_data);
        clean_forks_and_philosophers(main_data);
        return false;
    }
    return true;
}
bool init_mutex(t_main_data *main_data)
{
    if (!init_forks_mutex(main_data))
        return false;
    if (!init_print_mutex(main_data))
        return false;
    if (!init_death_mutex(main_data))
        return false;
    return true;
}