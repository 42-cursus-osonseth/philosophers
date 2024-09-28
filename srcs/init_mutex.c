/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:45:34 by max               #+#    #+#             */
/*   Updated: 2024/09/28 11:15:21 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_meals_completed_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.meals_completed, NULL) != 0)
	{
		print_error("Meals completed mutex initialization failed");
		destroy_array_mutex(main_data);
		clean_array(main_data);
		return (false);
	}
	return (true);
}

static bool	init_print_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.print_mutex, NULL) != 0)
	{
		print_error("Print mutex initialization failed");
		destroy_meals_completed_mutex(main_data);
		destroy_array_mutex(main_data);
		clean_array(main_data);
		return (false);
	}
	return (true);
}

static bool	init_death_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.death, NULL) != 0)
	{
		print_error("Death mutex initialization failed");
		destroy_meals_completed_mutex(main_data);
		destroy_print_mutex(main_data);
		destroy_array_mutex(main_data);
		clean_array(main_data);
		return (false);
	}
	return (true);
}

static bool	init_start_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.start, NULL) != 0)
	{
		print_error("Start mutex initialization failed");
		destroy_meals_completed_mutex(main_data);
		destroy_print_mutex(main_data);
		destroy_death_mutex(main_data);
		destroy_array_mutex(main_data);
		clean_array(main_data);
		return (false);
	}
	return (true);
}

bool	init_mutex(t_main_data *main_data)
{
	if (!init_meals_completed_mutex(main_data))
		return (false);
	if (!init_print_mutex(main_data))
		return (false);
	if (!init_death_mutex(main_data))
		return (false);
	if (!init_start_mutex(main_data))
		return (false);
	return (true);
}
