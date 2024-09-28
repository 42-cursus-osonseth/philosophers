/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:02 by max               #+#    #+#             */
/*   Updated: 2024/09/21 15:28:27 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	have_philosopher(char **argv)
{
	if (argv[1][0] == '0')
	{
		print_error("Error: The simulation cannot start because the number of\
philosophers is 0.");
		return (false);
	}
	return (true);
}

static bool	empty_arg(char **argv)
{
	if (!argv[1][0] || !argv[2][0] || !argv[3][0] || !argv[4][0] || (argv[5]
			&& !argv[5][0]))
	{
		print_error("Empty argument, Please enter a valid argument");
		return (true);
	}
	return (false);
}

static bool	argument_size_validation(t_args *args)
{
	if (args->number_of_philosophers == OVERFLOW
		|| args->time_to_die == OVERFLOW || args->time_to_eat == OVERFLOW
		|| args->time_to_sleep == OVERFLOW
		|| args->number_of_times_each_philosopher_must_eat == OVERFLOW)
	{
		print_error("The size of the arguments must be between 0 and INT MAX\n\
Please enter a valid size of the arguments");
		return (false);
	}
	return (true);
}

static bool	init_data_args(t_main_data *main_data, t_args *args, char **argv)
{
	if (empty_arg(argv))
		return (false);
	if (!have_philosopher(argv))
		return (false);
	init_args(args, argv);
	if (!argv[5])
		args->number_of_times_each_philosopher_must_eat = -1;
	else if (argv[5] && !init_meal_count(main_data, args, argv))
		return (false);
	if (!argument_size_validation(args))
		return (false);
	return (true);
}

bool	parse(t_main_data *main_data, int argc, char **argv)
{
	if (!check_number_args(argc))
		return (false);
	if (!check_has_only_number_in_args(argv))
		return (false);
	if (!init_data_args(main_data, &(main_data->shared_data.args), argv))
		return (false);
	return (true);
}
