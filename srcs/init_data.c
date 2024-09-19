/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:03:21 by max               #+#    #+#             */
/*   Updated: 2024/09/19 23:06:27 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool init_mutex(t_main_data *main_data)
{
    if (!init_forks_mutex(main_data))
        return false;
    if (!init_print_mutex(main_data))
        return false;
    if (!init_death_mutex(main_data))
        return false;
    if (!init_time_mutex(main_data))
        return false;
    return true;
}

static void init_philosopher(t_main_data *main_data)
{
    int i;
    i = 0;

    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        main_data->philosophers[i].id = i + 1;
        main_data->philosophers[i].shared_data = &(main_data->shared_data);
        main_data->philosophers[i].last_eaten_timestamp = 0;
        main_data->philosophers[i].meals_number = main_data->philosophers->shared_data->args.number_of_times_each_philosopher_must_eat;
        main_data->philosophers[i].action_start_time = 0;
        main_data->philosophers[i].action_current_time = 0;
        main_data->philosophers[i].action_time_elapsed = 0;
        i++;
    }
}

bool init_data(t_main_data *main_data)
{
    main_data->philosophers = malloc(sizeof(t_philosopher) * main_data->shared_data.args.number_of_philosophers);
    if (main_data->philosophers == NULL)
    {
        print_error("Malloc failed");
        return false;
    }
    init_philosopher(main_data);
    main_data->shared_data.forks = malloc(sizeof(pthread_mutex_t) * main_data->shared_data.args.number_of_philosophers);
    if (main_data->shared_data.forks == NULL)
    {
        clean_philosopher(main_data);
        print_error("Malloc failed");
        return false;
    }
    if (!init_mutex(main_data))
        return false;
    return true;
}
