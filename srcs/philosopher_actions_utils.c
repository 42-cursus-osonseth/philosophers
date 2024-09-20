/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:10:45 by max               #+#    #+#             */
/*   Updated: 2024/09/20 16:37:30 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping_usleep(t_philosopher *philosopher)
{
	philosopher->action_time_elapsed = 0;
	while (philosopher->action_time_elapsed < philosopher
		->shared_data->args.time_to_sleep)
	{
		usleep(50);
		philosopher->action_current_time = get_timestamp_in_ms();
		philosopher->action_time_elapsed = philosopher->action_current_time
			- philosopher->action_start_time;
	}
}

void	eating_usleep(t_philosopher *philosopher)
{
	philosopher->action_time_elapsed = 0;
	while (philosopher->action_time_elapsed < philosopher
		->shared_data->args.time_to_eat)
	{
		usleep(50);
		philosopher->action_current_time = get_timestamp_in_ms();
		philosopher->action_time_elapsed = philosopher->action_current_time
			- philosopher->action_start_time;
	}
}

void	even_philosophers_take_fork(t_philosopher *philosopher, int left_fork,
		int right_fork)
{
	pthread_mutex_lock(&philosopher->shared_data->forks[left_fork]);
	print_taking_forks(philosopher);
	pthread_mutex_lock(&philosopher->shared_data->forks[right_fork]);
	print_taking_forks(philosopher);
}

void	odd_philosophers_take_fork(t_philosopher *philosopher, int left_fork,
		int right_fork)
{
	pthread_mutex_lock(&philosopher->shared_data->forks[right_fork]);
	print_taking_forks(philosopher);
	pthread_mutex_lock(&philosopher->shared_data->forks[left_fork]);
	print_taking_forks(philosopher);
}

void	update_meals_number(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->shared_data->meals);
	philosopher->meals_number--;
	pthread_mutex_unlock(&philosopher->shared_data->meals);
}
