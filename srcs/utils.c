/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:53:26 by max               #+#    #+#             */
/*   Updated: 2024/09/18 18:25:55 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
	if (!str)
		return 0;
	int i;
	i = 0;

	while (str[i])
		i++;
	return i;
}

long int get_timestamp_in_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
long int ft_atoi(char *str)
{
	long int result;
	int len;

	len = ft_strlen(str);
	result = 0;
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	if (result < 0 || result > INT_MAX || len > 10)
		return OVERFLOW;
	return (result);
}
bool philosopher_is_dead(t_philosopher *philosopher)
{
	bool is_dead;
	pthread_mutex_lock(&philosopher->shared_data->death);
	is_dead = philosopher->shared_data->philosopher_is_dead;
	pthread_mutex_unlock(&philosopher->shared_data->death);
	return is_dead;
}