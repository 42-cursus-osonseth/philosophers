/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:54:04 by max               #+#    #+#             */
/*   Updated: 2024/08/30 10:22:37 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
