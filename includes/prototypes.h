/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:22:08 by max               #+#    #+#             */
/*   Updated: 2024/08/31 13:00:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "types.h"

//------print test a delete ---------
void print_args(t_main_data main_data);
void print_main_data(t_main_data main_data);
//-------------------------------
long int ft_atoi(char *str);
//---------- Error --------------
void print_error(char *str);
//---------- Parsing --------------
bool parse(t_args *args, int argc, char **argv);
bool check_has_only_number_in_args(char **argv);
bool check_number_args(int argc);
bool init_data(t_main_data *main_data);
//----------cleaning---------------
void destroy_mutex_and_clean ( t_main_data *main_data, int i);
void destroy_partial_mutexs(t_main_data *main_data, int count);
void destroy_all_mutexs(t_main_data *main_data);
void clean_philosopher(t_main_data *main_data);
void clean_forks(t_main_data *main_data);

long int get_timestamp_in_ms();

#endif