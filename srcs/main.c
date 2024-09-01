/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/09/01 15:33:20 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philosopher_routine(void *arg)
{

    t_philosopher *philosopher = (t_philosopher *)arg;

    while (1)
    {
        philosopher_sleeping(philosopher);
        philosopher_thinking(philosopher);
        philosopher_eating(philosopher);
    }

    return NULL;
}
void execute(t_main_data *main_data)
{
    int i;
    i = 0;
    pthread_t threads[main_data->shared_data.args.number_of_philosophers];
    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        if (pthread_create(&threads[i], NULL, philosopher_routine, &main_data->philosophers[i]) != 0)
        {
            print_error("Thread creation failed");
            return;
        }
        i++;
    }
    i = 0;
    while (i < main_data->shared_data.args.number_of_philosophers)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_main_data main_data = {0};

    if (parse(&(main_data.shared_data.args), argc, argv))
    {
        if (!init_data(&main_data))
            return 1;
        execute(&main_data);
        clean_and_destroy_all(&main_data);
    }
   

    return 0;
}
