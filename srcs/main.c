/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/09/23 18:48:02 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death_and_meals_limit(t_main_data *main_data)
{
	if (main_data->any_dead)
		return (true);
	if (main_data->has_meal_limit && main_data->meals == 0)
	{
		print_simulation_stop(main_data);
		return (true);
	}
	return (false);
}

bool	create_thread_array(t_main_data *main_data)
{
	main_data->threads = malloc(sizeof(pthread_t)
			* main_data->shared_data.args.number_of_philosophers);
	if (main_data->threads == NULL)
	{
		print_error("Malloc failed");
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
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
