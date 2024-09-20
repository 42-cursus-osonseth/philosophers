/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_init_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:03:21 by max               #+#    #+#             */
/*   Updated: 2024/09/20 21:27:04 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_start_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.start, NULL) != 0)
	{
		print_error("Meals mutex initialization failed");
		destroy_forks_mutex(main_data);
		destroy_print_mutex(main_data);
		destroy_death_mutex(main_data);
		destroy_time_mutex(main_data);
		destroy_meals_mutex(main_data);
		clean_forks_and_philosophers(main_data);
		return (false);
	}
	return (true);
}

static bool	init_mutex(t_main_data *main_data)
{
	if (!init_forks_mutex(main_data))
		return (false);
	if (!init_print_mutex(main_data))
		return (false);
	if (!init_death_mutex(main_data))
		return (false);
	if (!init_time_mutex(main_data))
		return (false);
	if (!init_start_mutex(main_data))
		return (false);
	return (true);
}

bool	create_and_init_data(t_main_data *main_data)
{
	if (!create_array(main_data))
		return (false);
	if (!init_data)
		return (false);
	if (!init_mutex(main_data))
		return (false);
	return (true);
}
