/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/09/26 14:36:42 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int update_limit(t_main_data *main_data, int i)
{
	bool reached_meals_limit;

	pthread_mutex_lock(&main_data->shared_data.meals_limit[i]);
	reached_meals_limit = main_data->philosophers[i].meals_limit_reached;
	pthread_mutex_unlock(&main_data->shared_data.meals_limit[i]);
	return (reached_meals_limit);
}

bool check_death_and_meals_limit(t_main_data *main_data)
{
	int meals_completed;

	meals_completed = update_limit_meals(main_data);

	if (main_data->any_dead)
		return (true);
	if (main_data->has_meal_limit && meals_completed == main_data->shared_data.args.number_of_philosophers)
	{
		print_simulation_stop(main_data);
		return (true);
	}
	return (false);
}

bool create_thread_array(t_main_data *main_data)
{
	main_data->threads = malloc(sizeof(pthread_t) * main_data->shared_data.args.number_of_philosophers);
	if (main_data->threads == NULL)
	{
		print_error("Malloc failed");
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	t_main_data(main_data) = {0};
	if (parse(&main_data, argc, argv))
	{
		if (!create_and_init_data(&main_data))
			return (1);
		execute(&main_data);
		clean_and_destroy_all(&main_data);
	}
	return (0);
}
