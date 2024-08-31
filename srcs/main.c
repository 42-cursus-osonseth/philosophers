/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/08/31 22:06:02 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philosopher_thinking(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA"%5zu"COLOR_RESET   COLOR_YELLOW"    is thinking"COLOR_RESET"\n",get_timestamp_in_ms(),philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
    usleep(philosopher->shared_data->args.time_to_eat * 1000);
}
void philosopher_sleeping(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->shared_data->print_mutex);
    printf(COLOR_GREEN "%13ld" COLOR_RESET COLOR_MAGENTA"%5zu"COLOR_RESET   COLOR_BLUE"    is sleeping"COLOR_RESET"\n", get_timestamp_in_ms(), philosopher->id);
    pthread_mutex_unlock(&philosopher->shared_data->print_mutex);
    usleep(philosopher->shared_data->args.time_to_sleep * 1000);
}

void *philosopher_routine(void *arg)
{
    
    t_philosopher *philosopher = (t_philosopher *)arg;
   
    philosopher_sleeping(philosopher);
    philosopher_thinking(philosopher);
    

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
        print_args(main_data);
        if (!init_data(&main_data))
            return 1;
        execute(&main_data);
        print_main_data(main_data);
    }
    destroy_mutex_and_clean(&main_data, -1);

    return 0;
}

//    struct timeval tv;

//    while (1) {
//         gettimeofday(&tv, NULL);

//         // Conversion des secondes en heures, minutes et secondes
//         // // int hours = 2 + (tv.tv_sec % 86400) / 3600;    // 86400 = 24*3600, nombre de secondes dans une journée
//         // int minutes = (tv.tv_sec % 3600) / 60;
//         int seconds = tv.tv_sec % 60;

//         // Microsecondes converties en millisecondes
//         int milliseconds = tv.tv_usec / 1000;

//         // Affichage du temps formaté
//         printf("%02d\\%03d\n", seconds, milliseconds);
//     }