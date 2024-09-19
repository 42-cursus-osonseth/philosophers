/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:10:45 by max               #+#    #+#             */
/*   Updated: 2024/09/19 23:18:41 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void sleeping_usleep(t_philosopher *philosopher)
{
    philosopher->action_time_elapsed = 0;
    while (philosopher->action_time_elapsed < philosopher->shared_data->args.time_to_sleep)
    {
        usleep(100);
        philosopher->action_current_time = get_timestamp_in_ms();
        philosopher->action_time_elapsed = philosopher->action_current_time - philosopher->action_start_time;
    }
}

void eating_usleep(t_philosopher *philosopher)
{
    philosopher->action_time_elapsed = 0;
    while (philosopher->action_time_elapsed < philosopher->shared_data->args.time_to_eat)
    {
        usleep(100);
        philosopher->action_current_time = get_timestamp_in_ms();
        philosopher->action_time_elapsed = philosopher->action_current_time - philosopher->action_start_time;
    }
}