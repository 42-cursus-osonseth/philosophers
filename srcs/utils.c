/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:53:26 by max               #+#    #+#             */
/*   Updated: 2024/09/28 11:16:07 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int	ft_atoi(char *str)
{
	long int	result;
	int			len;

	len = ft_strlen(str);
	result = 0;
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result < 0 || result > INT_MAX || len > 10)
		return (OVERFLOW);
	return (result);
}

bool	philosopher_is_dead(t_philosopher *philosopher)
{
	bool	is_dead;

	pthread_mutex_lock(&philosopher->shared_data->death);
	is_dead = philosopher->shared_data->philosopher_is_dead;
	pthread_mutex_unlock(&philosopher->shared_data->death);
	return (is_dead);
}

void	update_last_eaten_timestamp(t_philosopher *philosopher)
{
	int	i;

	i = philosopher->id - 1;
	pthread_mutex_lock(&philosopher->shared_data->time_last_meal[i]);
	philosopher->last_eaten_timestamp = get_timestamp_in_us();
	pthread_mutex_unlock(&philosopher->shared_data->time_last_meal[i]);
}

bool	check_death_and_meals_limit(t_main_data *main_data)
{
	int	meals_completed;

	meals_completed = update_limit_meals(main_data);
	if (main_data->any_dead)
		return (true);
	if (main_data->has_meal_limit && meals_completed
		== main_data->shared_data.args.number_of_philosophers)
	{
		print_simulation_stop(main_data);
		return (true);
	}
	return (false);
}
