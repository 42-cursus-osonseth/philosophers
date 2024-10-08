/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:22:08 by max               #+#    #+#             */
/*   Updated: 2024/09/28 11:16:30 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "types.h"

//---------------------- parsing -------------------------------
bool		parse(t_main_data *main_data, int argc, char **argv);
bool		check_has_only_number_in_args(char **argv);
bool		check_number_args(int argc);
bool		create_and_init_data(t_main_data *main_data);
//--------------------- parse_utils ----------------------------
void		init_args(t_args *args, char **argv);
bool		init_meal_count(t_main_data *main_data, t_args *args, char **argv);
//-------------------- init data -------------------------------
bool		create_array(t_main_data *main_data);
bool		create_thread_array(t_main_data *main_data);
bool		init_forks_mutex(t_main_data *main_data);
bool		init_time_last_meal_mutex(t_main_data *main_data);
bool		init_meals_limit_mutex(t_main_data *main_data);
bool		init_mutex(t_main_data *main_data);
//---------------------- execute -------------------------------
void		monitoring_of_philosophers(t_main_data *main_data);
void		*philosopher_routine(void *arg);
void		execute(t_main_data *main_data);
void		create_threads(t_main_data *main_data);
void		join_threads(t_main_data *main_data);
//------------------- execute utils ----------------------------
void		update_time_since_last_meal(t_main_data *main_data, int i);
int			update_limit_meals(t_main_data *main_data);
void		handle_one_philosopher(t_philosopher *philosopher);
bool		check_death_and_meals_limit(t_main_data *main_data);
int			update_limit(t_main_data *main_data, int i);
//------------------ philosopher actions ------------------------
void		philosopher_realease_forks(t_philosopher *philosopher);
void		philosopher_take_forks(t_philosopher *philosopher);
void		philosopher_thinking(t_philosopher *philosopher);
void		philosopher_sleeping(t_philosopher *philosopher);
void		philosopher_eating(t_philosopher *philosopher);
//---------------- philosopher actions utils --------------------
void		sleeping_usleep(t_philosopher *philosopher);
void		eating_usleep(t_philosopher *philosopher);
void		even_philosophers_take_fork(t_philosopher *philosopher,
				int left_fork, int right_fork);
void		odd_philosophers_take_fork(t_philosopher *philosopher,
				int left_fork, int right_fork);
void		update_meals_number(t_philosopher *philosopher);
void		update_last_eaten_timestamp(t_philosopher *philosopher);
//------------------------ utils --------------------------------
long int	get_timestamp_in_ms(void);
long int	get_precise_timestamp_in_ms(void);
long int	get_timestamp_in_us(void);
long int	ft_atoi(char *str);
bool		philosopher_is_dead(t_philosopher *philosopher);
//--------------------- cleaning -------------------------------
void		destroy_partial_forks_mutexs(t_main_data *main_data, int count);
void		destroy_partial_time_last_meal_mutexs(t_main_data *main_data,
				int count);
void		destroy_partial_meals_limit_mutexs(t_main_data *main_data,
				int count);
void		destroy_forks_mutex(t_main_data *main_data);
void		destroy_time_last_meal_mutex(t_main_data *main_data);
void		destroy_meals_limit_mutex(t_main_data *main_data);
void		destroy_array_mutex(t_main_data *main_data);
void		destroy_meals_completed_mutex(t_main_data *main_data);
void		destroy_print_mutex(t_main_data *main_data);
void		destroy_death_mutex(t_main_data *main_data);
void		destroy_start_mutex(t_main_data *main_data);
void		destroy_mutex(t_main_data *main_data);
void		clean_array(t_main_data *main_data);
void		clean_and_destroy_all(t_main_data *main_data);
//----------------------- print -------------------------------
void		print_thinking(t_philosopher *philosopher);
void		print_sleeping(t_philosopher *philosopher);
void		print_taking_forks(t_philosopher *philosopher);
void		print_eating(t_philosopher *philosopher);
void		print_simulation_stop(t_main_data *main_data);
void		print_error(char *str);

#endif