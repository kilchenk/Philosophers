/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:53:41 by kilchenk          #+#    #+#             */
/*   Updated: 2024/04/29 14:31:49 by kilchenk         ###   ########.fr       */
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

# define RESET		"\033[0m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define PURPLE		"\033[0;34m"
# define PINK		"\033[0;35m"
# define BLUE		"\033[0;36m"

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

int			ft_atoi(const char *nptr);
void		print(t_philo *p, int i);
void		ft_usleep(long int time);
void		ft_eat(t_philo *p);
void		*routine(void *phil);
uint64_t	current_time(void);
void		create_threads(t_philo *p);
void		init_threads(t_philo *p, t_data *param);
void		init_philo(t_philo *p, t_data *param);
t_data		*parse_data(char **argv);
void		error_output(void);
int			is_digit(char c);
int			arg_is_number(char *argv);
int			check_input(char **argv);
void		check_treads(t_philo *p);
int			check_death(t_philo *p);
void		free_all(t_philo *p);
void		join_threads(t_philo *p);

#endif