/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:25:21 by max               #+#    #+#             */
/*   Updated: 2024/09/18 13:16:55 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philosopher_realease_forks(t_philosopher *philosopher)
{
    int left_fork;
    int right_fork;

    left_fork = philosopher->id - 1;
    right_fork = philosopher->id % philosopher->shared_data->args.number_of_philosophers;

    if (philosopher->id % 2 == 0)
    {
        pthread_mutex_unlock(&philosopher->shared_data->forks[left_fork]);
        pthread_mutex_unlock(&philosopher->shared_data->forks[right_fork]);
    }
    else
    {
        pthread_mutex_unlock(&philosopher->shared_data->forks[right_fork]);
        pthread_mutex_unlock(&philosopher->shared_data->forks[left_fork]);
    }
}

void philosopher_take_forks(t_philosopher *philosopher)
{
    int left_fork;
    int right_fork;

    left_fork = philosopher->id - 1;
    right_fork = philosopher->id % philosopher->shared_data->args.number_of_philosophers;

    if (philosopher->shared_data->args.number_of_philosophers == 1)
    {
        pthread_mutex_lock(&philosopher->shared_data->forks[0]);
        print_taking_forks(philosopher);
        while (!philosopher_is_dead(philosopher))
            usleep(1000);
        pthread_mutex_unlock(&philosopher->shared_data->forks[0]);
        return;
    }
    if (philosopher->id % 2 == 0)
    {
        pthread_mutex_lock(&philosopher->shared_data->forks[left_fork]);
        print_taking_forks(philosopher);
        pthread_mutex_lock(&philosopher->shared_data->forks[right_fork]);
        print_taking_forks(philosopher);
    }
    else
    {
        pthread_mutex_lock(&philosopher->shared_data->forks[right_fork]);
        print_taking_forks(philosopher);
        pthread_mutex_lock(&philosopher->shared_data->forks[left_fork]);
        print_taking_forks(philosopher);
    }
}

void philosopher_thinking(t_philosopher *philosopher)
{

    long thinking_time;
    long factor;
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    factor = (philosopher->shared_data->args.time_to_die - philosopher->shared_data->args.time_to_eat - philosopher->shared_data->args.time_to_sleep) / philosopher->shared_data->args.number_of_philosophers;
    if (philosopher_is_dead(philosopher))
    {
        pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
        return;
    }
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
    if (philosopher->id % 2 == 0)
    {
        thinking_time = factor * 1000;
    }
    else
        thinking_time = factor * 500;
    print_thinking(philosopher);
    usleep(thinking_time);
}
void philosopher_sleeping(t_philosopher *philosopher)
{
    print_sleeping(philosopher);
    usleep(philosopher->shared_data->args.time_to_sleep * 1000);
}

void philosopher_eating(t_philosopher *philosopher)
{
    philosopher_take_forks(philosopher);
    if (philosopher_is_dead(philosopher))
        return;
    pthread_mutex_lock(&philosopher->shared_data->time);
    philosopher->last_eaten_timestamp = get_timestamp_in_ms();
    pthread_mutex_unlock(&philosopher->shared_data->time);
    print_eating(philosopher);
    usleep(philosopher->shared_data->args.time_to_eat * 1000);
    philosopher_realease_forks(philosopher);
}
