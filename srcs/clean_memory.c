/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:41:48 by max               #+#    #+#             */
/*   Updated: 2024/09/20 23:02:08 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_array(t_main_data *main_data)
{
	if (main_data->threads)
	{
		free(main_data->threads);
		main_data->threads = NULL;
	}
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
	destroy_array_mutex(main_data);
	destroy_mutex(main_data);
	clean_array(main_data);
}
