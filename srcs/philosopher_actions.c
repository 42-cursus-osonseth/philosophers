/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:25:21 by max               #+#    #+#             */
/*   Updated: 2024/09/01 02:42:59 by max              ###   ########.fr       */
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

    if (philosopher->id % 2 == 0)
    {
        pthread_mutex_lock(&philosopher->shared_data->forks[left_fork]);
        pthread_mutex_lock(&philosopher->shared_data->forks[right_fork]);
    }
    else
    {
        pthread_mutex_lock(&philosopher->shared_data->forks[right_fork]);
        pthread_mutex_lock(&philosopher->shared_data->forks[left_fork]);
    }
    print_takikng_forks(philosopher);
}

void philosopher_thinking(t_philosopher *philosopher)
{
    print_thinking(philosopher);
    philosopher->state = THINKING;
    usleep(philosopher->shared_data->args.time_to_eat * 1000);
}
void philosopher_sleeping(t_philosopher *philosopher)
{
    print_sleeping(philosopher);
    philosopher->state = SLEEPING;
    usleep(philosopher->shared_data->args.time_to_sleep * 1000);
}
void philosopher_eating(t_philosopher *philosopher)
{
    philosopher_take_forks(philosopher);
    philosopher->last_eaten_timestamp = get_timestamp_in_ms();
    print_eating(philosopher);
    philosopher->state = EATING;
    usleep(philosopher->shared_data->args.time_to_eat * 1000);
    philosopher_realease_forks(philosopher);
}