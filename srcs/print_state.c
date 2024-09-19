/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:31:46 by max               #+#    #+#             */
/*   Updated: 2024/09/19 23:07:56 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_thinking(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    if (philosopher_is_dead(philosopher))
    {
        pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
        return;
    }
    philosopher->shared_data->timestamp = get_timestamp_in_ms() - philosopher->shared_data->start_time;
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_YELLOW "    is thinking" COLOR_RESET "\n", philosopher->shared_data->timestamp, philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}

void print_sleeping(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    if (philosopher_is_dead(philosopher))
    {
        pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
        return;
    }
    philosopher->shared_data->timestamp = get_timestamp_in_ms() - philosopher->shared_data->start_time;
    philosopher->action_start_time = get_timestamp_in_ms();
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_PINK "    is sleeping" COLOR_RESET "\n", philosopher->shared_data->timestamp, philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}

void print_taking_forks(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    if (philosopher_is_dead(philosopher))
    {
        pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
        return;
    }
    philosopher->shared_data->timestamp = get_timestamp_in_ms() - philosopher->shared_data->start_time;
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_CYAN "    has taken a fork" COLOR_RESET "\n", philosopher->shared_data->timestamp, philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}

void print_eating(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    if (philosopher_is_dead(philosopher))
    {
        pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
        return;
    }
    philosopher->shared_data->timestamp = get_timestamp_in_ms() - philosopher->shared_data->start_time;
    philosopher->action_start_time = get_timestamp_in_ms();
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_BLUE "     is eating" COLOR_RESET "\n", philosopher->shared_data->timestamp, philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}
void print_simulation_stop(t_main_data *main_data)
{
    pthread_mutex_lock(&main_data->shared_data.print_mutex);
    printf(COLOR_GREEN "%13ld " COLOR_RESET, get_timestamp_in_ms() - main_data->shared_data.start_time);
    print_error("All philosophers have finished their meals, the simulation stops.");
    usleep(500);
    pthread_mutex_unlock(&main_data->shared_data.print_mutex);
}
