/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/08/29 21:46:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_args args = {0};

    if (parse(&args, argc, argv))
    {
        printf("Number of philosophers: %d\n", args.number_of_philosophers);
        printf("Time to die: %d ms\n", args.time_to_die);
        printf("Time to eat: %d ms\n", args.time_to_eat);
        printf("Time to sleep: %d ms\n", args.time_to_sleep);
        printf("Number of times each philosopher must eat: %d\n", args.number_of_times_each_philosopher_must_eat);
    }
    
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