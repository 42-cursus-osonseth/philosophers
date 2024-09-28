/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_init_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:03:21 by max               #+#    #+#             */
/*   Updated: 2024/09/28 11:18:05 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philosopher(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		main_data->philosophers[i].id = i + 1;
		main_data->philosophers[i].shared_data = &(main_data->shared_data);
		main_data->philosophers[i].last_eaten_timestamp = 0;
		main_data->philosophers[i].meals_number = main_data->philosophers
			->shared_data->args.number_of_times_each_philosopher_must_eat;
		main_data->philosophers[i].action_start_time = 0;
		main_data->philosophers[i].action_current_time = 0;
		main_data->philosophers[i].action_time_elapsed = 0;
		main_data->philosophers[i].meals_limit_reached = false;
		i++;
	}
}

static bool	init_mutex_array(t_main_data *main_data)
{
	if (!init_forks_mutex(main_data))
	{
		clean_array(main_data);
		return (false);
	}
	if (!init_time_last_meal_mutex(main_data))
	{
		destroy_forks_mutex(main_data);
		clean_array(main_data);
		return (false);
	}
	if (!init_meals_limit_mutex(main_data))
	{
		destroy_forks_mutex(main_data);
		destroy_time_last_meal_mutex(main_data);
		clean_array(main_data);
		return (false);
	}
	return (true);
}

static bool	init_data(t_main_data *main_data)
{
	init_philosopher(main_data);
	if (!init_mutex_array(main_data))
		return (false);
	if (!init_mutex(main_data))
		return (false);
	return (true);
}

bool	create_thread_array(t_main_data *main_data)
{
	main_data->threads = malloc(sizeof(pthread_t) * main_data->shared_data
			.args.number_of_philosophers);
	if (main_data->threads == NULL)
	{
		print_error("Malloc failed");
		return (false);
	}
	return (true);
}

bool	create_and_init_data(t_main_data *main_data)
{
	if (!create_array(main_data))
		return (false);
	if (!init_data(main_data))
		return (false);
	return (true);
}
