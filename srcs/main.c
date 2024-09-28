/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/09/28 11:15:25 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	update_limit(t_main_data *main_data, int i)
{
	bool	reached_meals_limit;

	pthread_mutex_lock(&main_data->shared_data.meals_limit[i]);
	reached_meals_limit = main_data->philosophers[i].meals_limit_reached;
	pthread_mutex_unlock(&main_data->shared_data.meals_limit[i]);
	return (reached_meals_limit);
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
