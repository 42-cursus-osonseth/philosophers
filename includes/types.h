/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:21:23 by max               #+#    #+#             */
/*   Updated: 2024/09/26 14:12:27 by max              ###   ########.fr       */
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
	int philosophers_meals_completed;
	t_args args;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
	pthread_mutex_t death;
	pthread_mutex_t *time_last_meal;
	pthread_mutex_t *meals_limit;
	pthread_mutex_t start;
	pthread_mutex_t meals_completed;

} t_shared_data;

typedef struct s_philosopher
{
	size_t id;
	bool meals_limit_reached;
	int meals_number;
	long int last_eaten_timestamp;
	long int action_start_time;
	long int action_current_time;
	long int action_time_elapsed;
	t_shared_data *shared_data;
} t_philosopher;

typedef struct s_main_data
{
	bool has_meal_limit;
	bool any_dead;
	long int time_since_last_meal;
	int meals;
	pthread_t *threads;
	t_philosopher *philosophers;
	t_shared_data shared_data;
} t_main_data;

#endif