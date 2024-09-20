/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:35:54 by max               #+#    #+#             */
/*   Updated: 2024/09/20 22:31:10 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main_data (main_data) = {0};
	if (parse(&main_data, argc, argv))
	{
		if (!create_and_init_data(&main_data))
			return (1);
		execute(&main_data);
		clean_and_destroy_all(&main_data);
	}
	return (0);
}
