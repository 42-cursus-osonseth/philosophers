/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:41:48 by max               #+#    #+#             */
/*   Updated: 2024/09/01 15:31:40 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clean_philosopher(t_main_data *main_data)
{
    if (main_data->philosophers)
    {
        free(main_data->philosophers);
        main_data->philosophers = NULL;
    }
}

void clean_forks(t_main_data *main_data)
{
    if (main_data->shared_data.forks)
    {
        free(main_data->shared_data.forks);
        main_data->shared_data.forks = NULL;
    }
}
void clean_forks_and_philosophers(t_main_data *main_data)
{
    clean_philosopher(main_data);
    clean_forks(main_data);
}
void clean_and_destroy_all(t_main_data *main_data)
{
    destroy_forks_mutex(main_data);
    destroy_print_mutex(main_data);
    destroy_death_mutex(main_data);
    clean_forks_and_philosophers(main_data);
}
