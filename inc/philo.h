/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:53:41 by kilchenk          #+#    #+#             */
/*   Updated: 2023/11/01 16:08:23 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define PURPLE		"\033[0;34m"
# define PINK		"\033[0;35m"

/* a structure to represent a philosopher */
typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	pthread_t		thread;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_data			*param;
}				t_philo;

/* a structure to represent all usefull data */
typedef struct s_data
{
	int				ready;
	int				eat_time;
	int				dead_time;
	int				sleep_time;
	int				eat_sum;
	int				over;
	int				philo_nb;
	int				check_sum;
	int				eated;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}				t_data;

#endif