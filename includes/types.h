/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:21:23 by max               #+#    #+#             */
/*   Updated: 2024/08/30 19:14:55 by max              ###   ########.fr       */
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
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;

} t_shared_data;

typedef struct s_philosopher
{
    size_t id;
    t_state state;
    t_shared_data *shared_data;
} t_philosopher;

typedef struct s_main_data
{
    t_philosopher *philosophers;
    t_shared_data shared_data;
} t_main_data;

#endif