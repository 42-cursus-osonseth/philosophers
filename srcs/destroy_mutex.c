/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:24:54 by max               #+#    #+#             */
/*   Updated: 2024/09/20 22:24:23 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_print_mutex(t_main_data *main_data)
{
	pthread_mutex_destroy(&main_data->shared_data.print_mutex);
}

void	destroy_death_mutex(t_main_data *main_data)
{
	pthread_mutex_destroy(&main_data->shared_data.death);
}

void	destroy_start_mutex(t_main_data *main_data)
{
	pthread_mutex_destroy(&main_data->shared_data.start);
}

void	destroy_mutex(t_main_data *main_data)
{
	destroy_print_mutex(main_data);
	destroy_death_mutex(main_data);
	destroy_start_mutex(main_data);
}
