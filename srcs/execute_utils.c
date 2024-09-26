/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:21:10 by max               #+#    #+#             */
/*   Updated: 2024/09/23 20:05:31 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_time_since_last_meal(t_main_data *main_data, int i)
{
	pthread_mutex_lock(&main_data->shared_data.time_last_meal[i]);
	main_data->time_since_last_meal = get_timestamp_in_ms()
		- main_data->philosophers[i].last_eaten_timestamp;
	pthread_mutex_unlock(&main_data->shared_data.time_last_meal[i]);
}

void	update_limit_meals(t_main_data *main_data, int i)
{
	pthread_mutex_lock(&main_data->shared_data.meals_limit[i]);
	main_data->meals += main_data->philosophers[i].meals_number;
	pthread_mutex_unlock(&main_data->shared_data.meals_limit[i]);
}

void	handle_one_philosopher(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->shared_data->forks[0]);
	print_taking_forks(philosopher);
	while (!philosopher_is_dead(philosopher))
		usleep(50);
	pthread_mutex_unlock(&philosopher->shared_data->forks[0]);
}

void	create_threads(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		if (pthread_create(&(main_data->threads)[i], NULL, philosopher_routine,
			&main_data->philosophers[i]) != 0)
		{
			print_error("Thread creation failed");
			return ;
		}
		i++;
	}
}

void	join_threads(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		if (pthread_join(main_data->threads[i], NULL) != 0)
		{
			print_error("Thread join failed");
			return ;
		}
		i++;
	}
}
