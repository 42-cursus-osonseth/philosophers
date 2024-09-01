/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:53:26 by max               #+#    #+#             */
/*   Updated: 2024/09/01 15:25:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int get_timestamp_in_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
long int ft_atoi(char *str)
{
	long int result;
	
	result = 0;
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result < 0 || result > INT_MAX)
		return OVERFLOW;
	return (result);
}