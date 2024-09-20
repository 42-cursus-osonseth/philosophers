/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_partial_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:16:44 by max               #+#    #+#             */
/*   Updated: 2024/09/20 22:01:45 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_partial_forks_mutexs(t_main_data *main_data, int count)
{
	int	i;

	i = 0;
	while (i <= count)
		pthread_mutex_destroy(&main_data->shared_data.forks[i++]);
}

void	destroy_partial_time_last_meal_mutexs(t_main_data *main_data, int count)
{
	int	i;

	i = 0;
	while (i <= count)
		pthread_mutex_destroy(&main_data->shared_data.time_last_meal[i++]);
}

void	destroy_partial_meals_limit_mutexs(t_main_data *main_data, int count)
{
	int	i;

	i = 0;
	while (i <= count)
		pthread_mutex_destroy(&main_data->shared_data.meals_limit[i++]);
}
