/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:41:48 by max               #+#    #+#             */
/*   Updated: 2024/09/20 22:06:48 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_array(t_main_data *main_data)
{
	if (main_data->philosophers)
	{
		free(main_data->philosophers);
		main_data->philosophers = NULL;
	}
	if (main_data->shared_data.time_last_meal)
	{
		free(main_data->shared_data.time_last_meal);
		main_data->shared_data.time_last_meal = NULL;
	}
	if (main_data->shared_data.meals_limit)
	{
		free(main_data->shared_data.meals_limit);
		main_data->shared_data.meals_limit = NULL;
	}
	if (main_data->shared_data.forks)
	{
		free(main_data->shared_data.forks);
		main_data->shared_data.forks = NULL;
	}
}

void	clean_and_destroy_all(t_main_data *main_data)
{
	destroy_forks_mutex(main_data);
	destroy_time_last_meal_mutex(main_data);
	destroy_meals_limit_mutex(main_data);


	clean_array(main_data);
	// destroy_print_mutex(main_data);
	// destroy_death_mutex(main_data);
	// destroy_time_mutex(main_data);
	// destroy_meals_mutex(main_data);
	// destroy_start_mutex(main_data);
	// clean_forks_and_philosophers(main_data);
}
