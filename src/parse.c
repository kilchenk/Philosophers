/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:05:38 by kilchenk          #+#    #+#             */
/*   Updated: 2023/11/09 18:07:35 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//parse
void	join_threads(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->param->philo_nb)
		pthread_join(p[i].thread, (void *)&p[i]);
}

//parse
void	create_threads(t_philo *p)
{
	int			i;
	long int	t;

	i = -1;
	while (++i < p->param->philo_nb)
		pthread_create(&p[i].thread, NULL, &routine, &p[i]);
	i = -1;
	t = current_time();
	while (++i < p->param->philo_nb)
	{
		p[i].start = t;
		p[i].meal = t;
	}
	p->param->ready = 1;
}

//parse
void	init_threads(t_philo *p, t_data *param)
{
	int	i;

	i = -1;
	while (++i < param->philo_nb)
	{
		pthread_mutex_init(p[i].forkl, NULL);
	}
	pthread_mutex_init(param->print, NULL);
	create_threads(p);
	check_treads(p);
}

//parse
void	init_philo(t_philo *p, t_data *param)
{
	int	i;

	i = -1;
	while (++i < param->philo_nb)
	{
		p[i].start = 0;
		p[i].id = i + 1;
		p[i].thread = 0;
		p[i].meal = 0;
		p[i].forkl = &param->fork[i];
		if (p[i].id == param->philo_nb)
		{
			p[i].forkr = &param->fork[0];
		}
		else
		{
			p[i].forkr = &param->fork[i + 1];
		}
		p[i].param = param;
		p[i].iter = 0;
	}
}

//parse
t_data	*parse_data(char **argv)
{
	t_data	*param;

	param = malloc(sizeof(t_data));
	if (param == NULL)
		return (NULL);
	param->print = malloc(sizeof(pthread_mutex_t));
	if (param->print == NULL)
		return (NULL);
	param->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (param->fork == NULL)
		return (NULL);
	param->dead_time = ft_atoi(argv[2]);
	param->eat_time = ft_atoi(argv[3]);
	param->check_sum = 0;
	param->sleep_time = ft_atoi(argv[4]);
	param->eated = 0;
	if (argv[5])
	{
		param->check_sum = 1;
		param->eat_sum = ft_atoi(argv[5]);
	}
	param->philo_nb = ft_atoi(argv[1]);
	param->ready = 0;
	param->over = 0;
	return (param);
}
