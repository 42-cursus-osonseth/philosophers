/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:18:09 by max               #+#    #+#             */
/*   Updated: 2024/09/20 16:08:59 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[1;31m"
# define COLOR_GREEN "\033[32m"
# define COLOR_YELLOW "\033[1;33m"
# define COLOR_BLUE "\033[1;34m"
# define COLOR_CYAN "\033[1;36m"
# define COLOR_MAGENTA "\033[1;35m"
# define COLOR_PINK "\033[38;5;205m"

# define OVERFLOW -2
# define CHECK_DEATH_MS 2

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

#endif