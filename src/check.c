/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:03:10 by kilchenk          #+#    #+#             */
/*   Updated: 2023/11/09 18:04:38 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//check
int	check_death(t_philo *p)
{
	long int	now;

	pthread_mutex_lock(p->param->print);
	now = current_time() - p->meal;
	if (now >= p->param->dead_time)
	{
		pthread_mutex_unlock(p->param->print);
		print(p, 5);
		pthread_mutex_unlock(p->forkl);
		pthread_mutex_unlock(p->forkr);
		return (1);
	}
	pthread_mutex_unlock(p->param->print);
	return (0);
}

//check
void	check_treads(t_philo *p)
{
	int	i;

	while (!p->param->ready)
		continue ;
	while (!p->param->over)
	{
		i = -1;
		while (++i < p->param->philo_nb)
		{
			if (check_death(&p[i]))
				p->param->over = 1;
		}
		if (p->param->eated == p->param->philo_nb)
			p->param->over = 1;
	}
	return ;
}

//check
int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		i++;
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
		|| (argv[5] && ft_atoi(argv[5]) <= 0))
		return (0);
	return (1);
}

//check
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

//check
int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}
