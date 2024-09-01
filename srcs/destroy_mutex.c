/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:24:54 by max               #+#    #+#             */
/*   Updated: 2024/09/01 15:27:40 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_forks_mutex(t_main_data *main_data)
{
    int i;
    i = 0;

    while (i < main_data->shared_data.args.number_of_philosophers)
        pthread_mutex_destroy(&main_data->shared_data.forks[i++]);
}
void destroy_print_mutex(t_main_data *main_data)
{
    pthread_mutex_destroy(&main_data->shared_data.print_mutex);
}
void destroy_death_mutex(t_main_data *main_data)
{
    pthread_mutex_destroy(&main_data->shared_data.death);
}

void destroy_partial_forks_mutexs(t_main_data *main_data, int count)
{
    int i;

    i = 0;
    while (i <= count)
        pthread_mutex_destroy(&main_data->shared_data.forks[i++]);
    clean_forks_and_philosophers(main_data);
}
