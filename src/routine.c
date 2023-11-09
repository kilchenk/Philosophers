/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:10:22 by kilchenk          #+#    #+#             */
/*   Updated: 2023/11/09 18:23:08 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//routine
void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->forkl);
	print(p, 1);
	pthread_mutex_lock(p->forkr);
	print(p, 6);
	p->meal = current_time();
	p->iter++;
	print(p, 2);
	ft_usleep(p->param->eat_time);
	pthread_mutex_unlock(p->forkl);
	pthread_mutex_unlock(p->forkr);
}

//routine
void	*routine(void *phil)
{
	t_philo	*p;

	p = (t_philo *)phil;
	while (!(p->param->ready))
		continue ;
	if (p->id % 2)
		ft_usleep(p->param->eat_time * 0.9 + 1);
	while (!(p->param->over))
	{
		ft_eat(p);
		pthread_mutex_lock(p->param->print);
		if (p->param->check_sum
			&& p->iter == p->param->eat_sum)
		{
			p->param->eated++;
			pthread_mutex_unlock(p->param->print);
			return (NULL);
		}
		pthread_mutex_unlock(p->param->print);
		print(p, 3);
		ft_usleep(p->param->sleep_time);
		print(p, 4);
	}
	return (NULL);
}

//errors
void	error_output(void)
{
	printf("Wrong input!\n");
	printf("Following args are needed or allowed\n");
	printf("number_of_philosophers time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}
