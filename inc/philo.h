/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:53:41 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/26 14:47:38 by kilchenk         ###   ########.fr       */
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
	struct s_data	*data;
	pthread_t		th;
	int				philo_id;
	int				meals_eaten;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

/* a structure to represent all usefull data */
typedef struct s_data
{
	pthread_t		*th_id;
	int				number_of_philo;
	int				number_of_meals;
	int				dead;
	int				finished;
	t_philo			*philos;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		death_time;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}				t_data;

#endif