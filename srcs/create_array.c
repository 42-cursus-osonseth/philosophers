/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:26:44 by mmauchre          #+#    #+#             */
/*   Updated: 2024/09/20 23:03:49 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	create_philosophers(t_main_data *main_data)
{
	main_data->philosophers = malloc(sizeof(t_philosopher)
			* main_data->shared_data.args.number_of_philosophers);
	if (main_data->philosophers == NULL)
	{
		clean_array(main_data);
		print_error("Malloc failed");
		return (false);
	}
	return (true);
}

static bool	create_forks_mutex(t_main_data *main_data)
{
	main_data->shared_data.forks = malloc(sizeof(pthread_mutex_t)
			* main_data->shared_data.args.number_of_philosophers);
	if (main_data->shared_data.forks == NULL)
	{
		clean_array(main_data);
		print_error("Malloc failed");
		return (false);
	}
	return (true);
}

static bool	create_time_last_meal_mutex(t_main_data *main_data)
{
	main_data->shared_data.time_last_meal = malloc(sizeof(pthread_mutex_t)
			* main_data->shared_data.args.number_of_philosophers);
	if (main_data->shared_data.time_last_meal == NULL)
	{
		clean_array(main_data);
		print_error("Malloc failed");
		return (false);
	}
	return (true);
}

static bool	create_meals_limit_mutex(t_main_data *main_data)
{
	main_data->shared_data.meals_limit = malloc(sizeof(pthread_mutex_t)
			* main_data->shared_data.args.number_of_philosophers);
	if (main_data->shared_data.meals_limit == NULL)
	{
		clean_array(main_data);
		print_error("Malloc failed");
		return (false);
	}
	return (true);
}

bool	create_array(t_main_data *main_data)
{
	if (!create_thread_array(main_data))
		return (false);
	if (!create_philosophers(main_data))
		return (false);
	if (!create_forks_mutex(main_data))
		return (false);
	if (!create_time_last_meal_mutex(main_data))
		return (false);
	if (!create_meals_limit_mutex(main_data))
		return (false);
	return (true);
}
