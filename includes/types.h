/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:21:23 by max               #+#    #+#             */
/*   Updated: 2024/09/01 14:35:49 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

typedef enum e_state
{
    CREATED,
    EATING,
    THINKING,
    SLEEPING,
    DEAD,
    
} t_state;

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
    t_args args;
    bool philosopher_is_dead;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t death;

} t_shared_data;

typedef struct s_philosopher
{
    size_t id;
    long int last_eaten_timestamp;
    t_state state;
    t_shared_data *shared_data;
} t_philosopher;

typedef struct s_main_data
{
    t_philosopher *philosophers;
    t_shared_data shared_data;
} t_main_data;

#endif