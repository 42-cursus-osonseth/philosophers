/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:11:17 by max               #+#    #+#             */
/*   Updated: 2024/09/21 16:08:53 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_philosopher_is_dead(t_main_data *main_data, int i)
{
	t_philosopher	*philosophers;

	philosophers = main_data->philosophers;
	pthread_mutex_lock(&main_data->shared_data.death);
	main_data->shared_data.philosopher_is_dead = true;
	pthread_mutex_unlock(&main_data->shared_data.death);
	main_data->any_dead = true;
	pthread_mutex_lock(&main_data->shared_data.print_mutex);
	printf(COLOR_RED "%13ld" COLOR_RESET COLOR_RED "%3zu"
		COLOR_RESET COLOR_RED " IS DEAD !" COLOR_RESET "\n",
		get_timestamp_in_ms() - main_data->shared_data.start_time,
		philosophers[i].id);
	usleep(500);
	pthread_mutex_unlock(&main_data->shared_data.print_mutex);
}

void	monitoring_of_philosophers(t_main_data *main_data)
{
	int	i;

	while (1)
	{
		i = 0;
		main_data->meals = 0;
		while (i++ < main_data->shared_data.args.number_of_philosophers)
		{
			update_time_since_last_meal(main_data, i - 1);
			if (main_data->time_since_last_meal >= main_data->shared_data
				.args.time_to_die)
			{
				handle_philosopher_is_dead(main_data, i - 1);
				break ;
			}
			update_limit_meals(main_data, i - 1);
		}
		if (main_data->any_dead)
			break ;
		if (main_data->has_meal_limit && main_data->meals == 0)
		{
			print_simulation_stop(main_data);
			break ;
		}
	}
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	pthread_mutex_lock(&(philosopher->shared_data->start));
	pthread_mutex_unlock(&(philosopher->shared_data->start));
	if (philosopher->id % 2 == 0)
		usleep(100);
	update_last_eaten_timestamp(philosopher);
	while (1)
	{
		if (philosopher_is_dead(philosopher))
			break ;
		philosopher_eating(philosopher);
		if (philosopher_is_dead(philosopher) || philosopher->meals_number == 0)
			break ;
		philosopher_sleeping(philosopher);
		if (philosopher_is_dead(philosopher))
			break ;
		philosopher_thinking(philosopher);
	}
	return (NULL);
}

void	init_time_last_meal(t_main_data *main_data)
{
	int	i;

	i = 0;
	while (i < main_data->shared_data.args.number_of_philosophers)
	{
		main_data->philosophers[i].last_eaten_timestamp = get_timestamp_in_ms();
		i++;
	}
}

void	execute(t_main_data *main_data)
{
	pthread_mutex_lock(&(main_data->shared_data.start));
	create_threads(main_data);
	main_data->shared_data.start_time = get_timestamp_in_ms();
	init_time_last_meal(main_data);
	pthread_mutex_unlock(&(main_data->shared_data.start));
	usleep(5000);
	monitoring_of_philosophers(main_data);
	join_threads(main_data);
}
