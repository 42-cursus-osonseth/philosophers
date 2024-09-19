/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:22:08 by max               #+#    #+#             */
/*   Updated: 2024/09/19 08:24:44 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "types.h"

bool philosopher_is_dead(t_philosopher *philosopher);

//----------------------- print -------------------------------
void print_thinking(t_philosopher *philosopher);
void print_sleeping(t_philosopher *philosopher);
void print_taking_forks(t_philosopher *philosopher);
void print_eating(t_philosopher *philosopher);
void print_simulation_stop (t_main_data *main_data);
void print_error(char *str);
//---------------------- parsing -------------------------------
bool parse(t_main_data *main_data, int argc, char **argv);
bool check_has_only_number_in_args(char **argv);
bool check_number_args(int argc);
bool init_data(t_main_data *main_data);
bool init_mutex(t_main_data *main_data);
//-------------------- init mutex ------------------------------
bool init_forks_mutex(t_main_data *main_data);
bool init_print_mutex(t_main_data *main_data);
bool init_death_mutex(t_main_data *main_data);
bool init_time_mutex(t_main_data *main_data);
//---------------------- execute -------------------------------
void monitoring_of_philosophers(t_main_data *main_data);
void *philosopher_routine(void *arg);
void execute(t_main_data *main_data);
//--------------------- cleaning -------------------------------
void destroy_partial_forks_mutexs(t_main_data *main_data, int count);
void destroy_forks_mutex(t_main_data *main_data);
void destroy_print_mutex(t_main_data *main_data);
void destroy_death_mutex(t_main_data *main_data);
void destroy_time_mutex(t_main_data *main_data);
void destroy_meals_mutex(t_main_data *main_data);
void clean_philosopher(t_main_data *main_data);
void clean_forks(t_main_data *main_data);
void clean_forks_and_philosophers(t_main_data *main_data);
void clean_and_destroy_all(t_main_data *main_data);
//------------------ philosopher_action ------------------------
void philosopher_realease_forks(t_philosopher *philosopher);
void philosopher_take_forks(t_philosopher *philosopher);
void philosopher_thinking(t_philosopher *philosopher);
void philosopher_sleeping(t_philosopher *philosopher);
void philosopher_eating(t_philosopher *philosopher);
//------------------------ utils --------------------------------
long int get_timestamp_in_ms();
long int ft_atoi(char *str);
bool philosopher_is_dead(t_philosopher *philosopher);

#endif