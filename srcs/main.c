/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/09/02 16:18:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitoring_of_philosophers(t_main_data *main_data)
{
    t_philosopher *philosophers = main_data->philosophers;
    int i;
    bool any_dead;
    long int time;
    while (1)
    {
        usleep(100);
        i = 0;
        any_dead = false;
        while (i < main_data->shared_data.args.number_of_philosophers)
        {
            time = get_timestamp_in_ms() - philosophers[i].last_eaten_timestamp;
            if (time >= main_data->shared_data.args.time_to_die)
            {
                pthread_mutex_lock(&main_data->shared_data.death);
                main_data->shared_data.philosopher_is_dead = true;
                pthread_mutex_unlock(&main_data->shared_data.death);
                any_dead = true;
                pthread_mutex_lock(&main_data->shared_data.print_mutex);
                printf(COLOR_RED "%13ld" COLOR_RESET COLOR_RED " Philo %3zu" COLOR_RESET COLOR_RED "    IS DEAD !" COLOR_RESET "\n", get_timestamp_in_ms(), philosophers[i].id);
                usleep(500);
                pthread_mutex_unlock(&main_data->shared_data.print_mutex);
                break;
            }
            i++;
        }
        if (any_dead)
            break;
    }
}

void *philosopher_routine(void *arg)
{

    t_philosopher *philosopher = (t_philosopher *)arg;
    philosopher->last_eaten_timestamp = get_timestamp_in_ms();
    while (1)
    {
        philosopher_eating(philosopher);
        if (philosopher_is_dead(philosopher))
            break;
        philosopher_sleeping(philosopher);
        if (philosopher_is_dead(philosopher))
            break;
        philosopher_thinking(philosopher);
        if (philosopher_is_dead(philosopher))
            break;
    }

    return NULL;
}
void execute(t_main_data *main_data)
{
    int i;
    i = 0;
    pthread_t threads[main_data->shared_data.args.number_of_philosophers];
    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        if (pthread_create(&threads[i], NULL, philosopher_routine, &main_data->philosophers[i]) != 0)
        {
            print_error("Thread creation failed");
            return;
        }
        if (pthread_detach(threads[i]) != 0)
        {
            print_error("Thread detach failed");
            return;
        }
        i++;
    }
    monitoring_of_philosophers(main_data);
}

int main(int argc, char **argv)
{
    t_main_data main_data = {0};

    if (parse(&(main_data.shared_data.args), argc, argv))
    {   //print_args(main_data);
        if (!init_data(&main_data))
            return 1;
        execute(&main_data);
        clean_and_destroy_all(&main_data);
    }

    return 0;
}
