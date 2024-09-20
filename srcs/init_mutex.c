/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:45:34 by max               #+#    #+#             */
/*   Updated: 2024/09/20 21:28:34 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



bool	init_print_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.print_mutex, NULL) != 0)
	{
		print_error("Print mutex initialization failed");
		destroy_forks_mutex(main_data);
		clean_forks_and_philosophers(main_data);
		return (false);
	}
	return (true);
}

bool	init_death_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.death, NULL) != 0)
	{
		print_error("Death mutex initialization failed");
		destroy_forks_mutex(main_data);
		destroy_print_mutex(main_data);
		clean_forks_and_philosophers(main_data);
		return (false);
	}
	return (true);
}

bool	init_time_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.time, NULL) != 0)
	{
		print_error("Time mutex initialization failed");
		destroy_forks_mutex(main_data);
		destroy_print_mutex(main_data);
		destroy_death_mutex(main_data);
		clean_forks_and_philosophers(main_data);
		return (false);
	}
	return (true);
}

bool	init_meals_mutex(t_main_data *main_data)
{
	if (pthread_mutex_init(&main_data->shared_data.meals, NULL) != 0)
	{
		print_error("Meals mutex initialization failed");
		destroy_forks_mutex(main_data);
		destroy_print_mutex(main_data);
		destroy_death_mutex(main_data);
		destroy_time_mutex(main_data);
		clean_forks_and_philosophers(main_data);
		return (false);
	}
	return (true);
}
