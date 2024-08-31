/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:41:48 by max               #+#    #+#             */
/*   Updated: 2024/08/30 19:30:43 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clean_philosopher(t_main_data *main_data)
{
    free(main_data->philosophers);
    main_data->philosophers = NULL;
}

void clean_forks(t_main_data *main_data)
{
    free(main_data->shared_data.forks);
    main_data->shared_data.forks = NULL;
}

void destroy_all_mutexs(t_main_data *main_data)
{
    int i;
    i = 0;

    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        pthread_mutex_destroy(&main_data->shared_data.forks[i]);
        i++;
    }
}

void destroy_partial_mutexs(t_main_data *main_data, int count)
{
    int i;

    i = 0;

    while (i <= count)
    {
        pthread_mutex_destroy(&main_data->shared_data.forks[i]);
        i++;
    }
}

void destroy_mutex_and_clean(t_main_data *main_data, int i)
{
    if (i >= 0)
    {
        destroy_partial_mutexs(main_data, i);
        clean_philosopher(main_data);
        clean_forks(main_data);
    }
    else
    {
        destroy_all_mutexs(main_data);
        clean_philosopher(main_data);
        clean_forks(main_data);
    }
}
