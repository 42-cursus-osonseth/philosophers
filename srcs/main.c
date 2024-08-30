/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/08/30 16:02:28 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool init_data ( t_main_data *main_data)
{
    main_data->philosophers = malloc(sizeof(t_philosopher) * main_data->shared_data.args.number_of_philosophers);
    if (main_data->philosophers == NULL)
    {
        print_error("Malloc failed");
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
 t_main_data main_data = {0};

  
    if (parse(&(main_data.shared_data.args), argc, argv))
    {
        print_args(main_data);
        if (!init_data (&main_data))
            
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