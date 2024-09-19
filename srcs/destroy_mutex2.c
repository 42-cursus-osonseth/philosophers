/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:16:44 by max               #+#    #+#             */
/*   Updated: 2024/09/20 00:51:08 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_meals_mutex(t_main_data *main_data)
{
    pthread_mutex_destroy(&main_data->shared_data.meals);
}
void destroy_start_mutex(t_main_data *main_data)
{
    pthread_mutex_destroy(&main_data->shared_data.start);
}