/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:37:50 by max               #+#    #+#             */
/*   Updated: 2024/08/30 10:32:54 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static bool ft_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

static bool ft_is_all_num(char *str)
{
    while (*str)
    {
        if (!ft_is_num(*str))
            return false;
        str++;
    }
    return true;
}

bool check_has_only_number_in_args(char **argv)
{
    int i;
    i = 0;

    while (argv[++i])
    {
        if (!ft_is_all_num(argv[i]))
        {
            print_error("Please enter arguments as positive integers");
            return false;
        }
    }
    return true;
}
bool check_number_args(int argc)
{
    if (argc != 5 && argc != 6)
    {
        print_error("Invalid number of arguments, please enter 4 or 5 arguments");
        return false;
    }
    return true;
}