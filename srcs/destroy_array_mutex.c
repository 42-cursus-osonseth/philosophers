/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_array_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:35:23 by mmauchre          #+#    #+#             */
/*   Updated: 2024/09/20 22:02:13 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks_mutex(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
		pthread_mutex_destroy(&main_data->shared_data.forks[i++]);
}

void	destroy_time_last_meal_mutex(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
		pthread_mutex_destroy(&main_data->shared_data.time_last_meal[i++]);
}

void	destroy_meals_limit_mutex(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
		pthread_mutex_destroy(&main_data->shared_data.meals_limit[i++]);
}
