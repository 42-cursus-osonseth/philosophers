/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:25:21 by max               #+#    #+#             */
/*   Updated: 2024/09/28 10:14:50 by max              ###   ########.fr       */
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
		handle_one_philosopher(philosopher);
		return;
	}
	if (philosopher->id % 2 == 0)
		even_philosophers_take_fork(philosopher, left_fork, right_fork);
	else
		odd_philosophers_take_fork(philosopher, left_fork, right_fork);
}

void philosopher_thinking(t_philosopher *philosopher)
{
	long thinking_time;
	int gap;

	gap = (philosopher->shared_data->args.time_to_eat + philosopher->shared_data->args.time_to_sleep) / philosopher->shared_data->args.number_of_philosophers;
	if (philosopher->shared_data->args.number_of_philosophers % 2 == 0)
		print_thinking(philosopher);

	else if (philosopher->shared_data->args.number_of_philosophers > 14 )
	{
		
		if (philosopher->id % 2 == 0)
			thinking_time = gap * 20;
		else
			thinking_time = (gap / 2) * 20;
		print_thinking(philosopher);
		usleep(thinking_time);
	}
	else
	{
		if (philosopher->id % 2 == 0)
			thinking_time = gap * 5;
		else
			thinking_time = (gap / 2) * 5;
		print_thinking(philosopher);
		usleep(thinking_time);
	}
}

void philosopher_sleeping(t_philosopher *philosopher)
{
	print_sleeping(philosopher);
	sleeping_usleep(philosopher);
}

void philosopher_eating(t_philosopher *philosopher)
{
	philosopher_take_forks(philosopher);
	if (philosopher_is_dead(philosopher))
	{
		if (philosopher->shared_data->args.number_of_philosophers != 1)
			philosopher_realease_forks(philosopher);
		return;
	}
	update_last_eaten_timestamp(philosopher);
	print_eating(philosopher);
	eating_usleep(philosopher);
	philosopher_realease_forks(philosopher);
	if (philosopher->meals_number > 0)
		update_meals_number(philosopher);
}
