/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:34:23 by max               #+#    #+#             */
/*   Updated: 2024/08/31 14:55:10 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_args(t_main_data main_data)
{
    printf("Number of philosophers: %d\n", main_data.shared_data.args.number_of_philosophers);
    printf("Time to die: %d ms\n", main_data.shared_data.args.time_to_die);
    printf("Time to eat: %d ms\n", main_data.shared_data.args.time_to_eat);
    printf("Time to sleep: %d ms\n", main_data.shared_data.args.time_to_sleep);
    printf("Number of times each philosopher must eat: %d\n", main_data.shared_data.args.number_of_times_each_philosopher_must_eat);
}

void print_main_data(t_main_data main_data)
{
    int i = 0;

    while (i < main_data.shared_data.args.number_of_philosophers)
    {
        printf("Philosopher ID = %zu\n", main_data.philosophers[i].id);
        printf("Philosopher state = %d\n", main_data.philosophers[i].state);
        printf("Philosopher shared data = %p\n", main_data.philosophers[i].shared_data);
        printf("Mutex %d address = %p\n", i, (void *)&main_data.shared_data.forks[i]);
        i++;
    }
}