/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:08:26 by kilchenk          #+#    #+#             */
/*   Updated: 2023/11/09 18:10:21 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//utils
void	free_all(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->param->philo_nb)
	{
		pthread_mutex_destroy(p[i].forkl);
	}
	pthread_mutex_destroy(p->param->print);
	free(p->param->print);
	free(p->param->fork);
	free(p->param);
	free(p);
}

//utils
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	sum;

	sum = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum *= 10;
		sum += nptr[i] - '0';
		i++;
	}
	sum *= sign;
	return (sum);
}

//utils 
void	print(t_philo *p, int i)
{
	pthread_mutex_lock(p->param->print);
	if (p->param->over)
	{
		pthread_mutex_unlock(p->param->print);
		return ;
	}
	if (i == 1)
		printf("%s%llu %d has taken left fork%s\n", PURPLE,
			current_time() - p->start, p->id, RESET);
	else if (i == 2)
		printf("%s%llu %d is eatting%s\n", GREEN, current_time() - p->start,
			p->id, RESET);
	else if (i == 3)
		printf("%s%llu %d is sleeping%s\n", BLUE, current_time() - p->start,
			p->id, RESET);
	else if (i == 4)
		printf("%s%llu %d is thinking%s\n", YELLOW, current_time() - p->start,
			p->id, RESET);
	else if (i == 5)
		printf("%s%llu %d died %s\n", RED, current_time() - p->start,
			p->id, RESET);
	else if (i == 6)
		printf("%s%llu %d has taken right fork%s\n", PINK,
			current_time() - p->start, p->id, RESET);
	pthread_mutex_unlock(p->param->print);
}

//utils
void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = current_time();
	while ((current_time() - start_time) < (unsigned long long) time)
		usleep(150);
}

//utils
uint64_t	current_time(void)
{
	uint64_t		milliseconds;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}
