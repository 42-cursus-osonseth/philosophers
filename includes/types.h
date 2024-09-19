/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:21:23 by max               #+#    #+#             */
/*   Updated: 2024/09/19 08:39:37 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

typedef struct s_args
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

} t_args;

typedef struct s_shared_data
{
    bool philosopher_is_dead;
    long int timestamp;
    long int start_time;
    t_args args;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t death;
    pthread_mutex_t time;
    pthread_mutex_t meals;
    

} t_shared_data;

typedef struct s_philosopher
{
    size_t id;
    long int last_eaten_timestamp;
    int meals_number;
    t_shared_data *shared_data;
} t_philosopher;

typedef struct s_main_data
{
    bool has_meal_limit;
    bool any_dead;
    t_philosopher *philosophers;
    t_shared_data shared_data;
} t_main_data;

#endif