/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:29:07 by mmauchre          #+#    #+#             */
/*   Updated: 2024/09/20 21:55:14 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_forks_mutex(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		if (pthread_mutex_init(&main_data->shared_data.forks[i], NULL) != 0)
		{
			print_error("Forks mutex initialization failed");
			destroy_partial_forks_mutexs(main_data, i);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_time_last_meal_mutex(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		if (pthread_mutex_init(&main_data->shared_data.time_last_meal[i], NULL)
			!= 0)
		{
			print_error("Time_last_meal mutex initialization failed");
			destroy_partial_time_last_meal_mutexs(main_data, i);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_meals_limit_mutex(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		if (pthread_mutex_init(&main_data->shared_data.meals_limit[i], NULL)
			!= 0)
		{
			print_error("Meals_limit mutex initialization failed");
			destroy_partial_meals_limit_mutexs(main_data, i);
			return (false);
		}
		i++;
	}
	return (true);
}
