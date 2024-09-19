/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:18:17 by max               #+#    #+#             */
/*   Updated: 2024/09/20 00:28:25 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_args(t_args *args, char **argv)
{
    args->number_of_philosophers = (int)ft_atoi(argv[1]);
    args->time_to_die = (int)ft_atoi(argv[2]);
    args->time_to_eat = (int)ft_atoi(argv[3]);
    args->time_to_sleep = (int)ft_atoi(argv[4]);
}
bool init_meal_count(t_main_data *main_data, t_args *args, char **argv)
{
    args->number_of_times_each_philosopher_must_eat = (int)ft_atoi(argv[5]);
    if (args->number_of_times_each_philosopher_must_eat == 0)
    {
        print_error("The number of times each philosopher must eat should be at least 1");
        return false;
    }
    main_data->has_meal_limit = true;
    return true;
}