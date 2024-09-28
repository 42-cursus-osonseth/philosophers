/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 06:19:53 by max               #+#    #+#             */
/*   Updated: 2024/09/28 11:21:31 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_precise_timestamp_in_ms(void)
{
	struct timeval	tv;

	while (1)
	{
		gettimeofday(&tv, NULL);
		if (tv.tv_usec < 10)
			break ;
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long int	get_timestamp_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long int	get_timestamp_in_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}
