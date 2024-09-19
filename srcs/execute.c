/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:11:17 by max               #+#    #+#             */
/*   Updated: 2024/09/19 23:56:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void handle_philosopher_is_dead(t_main_data *main_data, int i)
{
    t_philosopher *philosophers = main_data->philosophers;
    pthread_mutex_lock(&main_data->shared_data.death);
    main_data->shared_data.philosopher_is_dead = true;
    pthread_mutex_unlock(&main_data->shared_data.death);
    main_data->any_dead = true;
    pthread_mutex_lock(&main_data->shared_data.print_mutex);
    printf(COLOR_RED "%13ld" COLOR_RESET COLOR_RED " Philo %3zu" COLOR_RESET COLOR_RED "    IS DEAD !" COLOR_RESET "\n", get_timestamp_in_ms() - main_data->shared_data.start_time, philosophers[i].id);
    usleep(500);
    pthread_mutex_unlock(&main_data->shared_data.print_mutex);
}

void monitoring_of_philosophers(t_main_data *main_data)
{
    int i;

    while (1)
    {
        usleep(100);
        i = 0;
        main_data->meals = 0;
        while (i++ < main_data->shared_data.args.number_of_philosophers)
        {
            update_time_since_last_meal(main_data, i - 1);
            if (main_data->time_since_last_meal >= main_data->shared_data.args.time_to_die)
            {
                handle_philosopher_is_dead(main_data, i - 1);
                break;
            }
            update_limit_meals(main_data, i - 1);
        }
        if (main_data->any_dead)
            break;
        if (main_data->has_meal_limit && main_data->meals == 0)
        {
            print_simulation_stop(main_data);
            break;
        }
    }
}

void *philosopher_routine(void *arg)
{

    t_philosopher *philosopher = (t_philosopher *)arg;
    update_last_eaten_timestamp(philosopher);
    while (1)
    {
        if (philosopher_is_dead(philosopher))
            break;
        philosopher_eating(philosopher);
        if (philosopher_is_dead(philosopher) || philosopher->meals_number == 0)
            break;
        philosopher_sleeping(philosopher);
        if (philosopher_is_dead(philosopher))
            break;
        philosopher_thinking(philosopher);
    }

    return NULL;
}
void execute(t_main_data *main_data)
{
    int i;
    pthread_t threads[main_data->shared_data.args.number_of_philosophers];

    main_data->shared_data.start_time = get_timestamp_in_ms();
    i = 0;
    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        if (pthread_create(&threads[i], NULL, philosopher_routine, &main_data->philosophers[i]) != 0)
        {
            print_error("Thread creation failed");
            return;
        }
        i++;
    }
    monitoring_of_philosophers(main_data);
    i = 0;
    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            print_error("Thread join failed");
            return;
        }
        i++;
    }
}