/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:31:46 by max               #+#    #+#             */
/*   Updated: 2024/09/02 13:12:45 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_thinking(t_philosopher *philosopher)
{
    if (philosopher_is_dead(philosopher))
        return;
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_YELLOW "    is thinking" COLOR_RESET "\n", get_timestamp_in_ms(), philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}

void print_sleeping(t_philosopher *philosopher)
{
    if (philosopher_is_dead(philosopher))
        return;
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_PINK "    is sleeping" COLOR_RESET "\n", get_timestamp_in_ms(), philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}

void print_takikng_forks(t_philosopher *philosopher)
{
    if (philosopher_is_dead(philosopher))
        return;
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_CYAN "    has taken forks" COLOR_RESET "\n", get_timestamp_in_ms(), philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}

void print_eating(t_philosopher *philosopher)
{
    if (philosopher_is_dead(philosopher))
        return;
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA " Philo %3zu" COLOR_RESET COLOR_BLUE "     is eating" COLOR_RESET "\n", get_timestamp_in_ms(), philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
}
