/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:25:21 by max               #+#    #+#             */
/*   Updated: 2024/09/02 13:10:38 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void philosopher_take_forks_odd(t_philosopher *philosopher)
// {
//     int left_fork;
//     int right_fork;

//     left_fork = philosopher->id - 1;
//     right_fork = (philosopher->id % philosopher->shared_data->args.number_of_philosophers);

//     pthread_mutex_lock(&philosopher->shared_data->print_mutex);
//     printf("%13ld  %zu try take fork righ [%d]\n", get_timestamp_in_ms(), philosopher->id,right_fork);
//     pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
//     pthread_mutex_lock(&philosopher->shared_data->forks[right_fork]);
//     pthread_mutex_lock(&philosopher->shared_data->print_mutex);
//      printf("%13ld  %zu taked fork righ [%d]\n", get_timestamp_in_ms(), philosopher->id,right_fork);
//     pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
//     pthread_mutex_lock(&philosopher->shared_data->print_mutex);
//     printf("%13ld  %zu try take fork left [%d]\n", get_timestamp_in_ms(), philosopher->id,left_fork);
//     pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
//     pthread_mutex_lock(&philosopher->shared_data->forks[left_fork]);
//     pthread_mutex_lock(&philosopher->shared_data->print_mutex);
//     printf("%13ld  %zu taked fork righ [%d]\n", get_timestamp_in_ms(), philosopher->id,left_fork);
//     pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
//     print_takikng_forks(philosopher);
// }

// void philosopher_realease_forks_odd(t_philosopher *philosopher)
// {
//     int left_fork;
//     int right_fork;

//     left_fork = philosopher->id - 1;
//     right_fork = (philosopher->id % philosopher->shared_data->args.number_of_philosophers);

//     pthread_mutex_unlock(&philosopher->shared_data->forks[right_fork]);
//     pthread_mutex_unlock(&philosopher->shared_data->forks[left_fork]);
// }

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

// void philosopher_take_forks(t_philosopher *philosopher)
// {
//     if (philosopher->shared_data->args.number_of_philosophers % 2 == 0)
//         philosopher_take_forks_even(philosopher);
//     else
//         philosopher_take_forks_odd(philosopher);
// }

// void philosopher_realease_forks(t_philosopher *philosopher)
// {
//     if (philosopher->shared_data->args.number_of_philosophers % 2 == 0)
//         philosopher_realease_forks_even(philosopher);
//     else
//         philosopher_realease_forks_odd(philosopher);
// }

void philosopher_thinking(t_philosopher *philosopher)
{

    long thinking_time;
    long factor;
    factor = (philosopher->shared_data->args.time_to_die - philosopher->shared_data->args.time_to_eat - philosopher->shared_data->args.time_to_sleep) / philosopher->shared_data->args.number_of_philosophers;

    if (philosopher->id % 2 == 0)
    {
        thinking_time = factor * 1000;
    }
    else
        thinking_time = factor * 500;
    print_thinking(philosopher);
    philosopher->state = THINKING;
    usleep(thinking_time);
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
