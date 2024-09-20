/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:11:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/09/20 22:07:31 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosopher(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		main_data->philosophers[i].id = i + 1;
		main_data->philosophers[i].shared_data = &(main_data->shared_data);
		main_data->philosophers[i].last_eaten_timestamp = 0;
		main_data->philosophers[i].meals_number = main_data->philosophers->shared_data->args.number_of_times_each_philosopher_must_eat;
		main_data->philosophers[i].action_start_time = 0;
		main_data->philosophers[i].action_current_time = 0;
		main_data->philosophers[i].action_time_elapsed = 0;
		i++;
	}
}
bool	init_mutex_array(t_main_data *main_data)
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

bool	init_data(t_main_data *main_data)
{
	init_philosopher(main_data);
	if (!init_mutex_array(main_data))
		return (false);
	return (true);
}
