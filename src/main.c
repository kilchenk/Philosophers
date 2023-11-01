/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:52:55 by kilchenk          #+#    #+#             */
/*   Updated: 2023/11/01 18:59:23 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//utils
void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < (unsigned long long) time)
		usleep(150);
}

//routine
void	*routine(void)
{
	void	*phil;
	t_philo	*p;

	p = (t_philo *)phil;
	while (!(p->param->ready))
		continue ;
	if (!(p->id % 2))
		ft_usleep(p->param->eat_time * 0.9 + 1);
	while (!(p->param->over))
	{
		//eat func
		pthread_mutex_lock(p->param->print);
		if (p->param->check_sum && p->iter
			== p->param->eat_sum)
		{
			p->param->eated++;
			pthread_mutex_unlock(p->param->print);
			return (NULL);
		}
		pthread_mutex_unlock(p->param->print);
		//print func
		ft_usleep(p->param->sleep_time);
		//print func
	}

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

//parse
void	create_threads(t_philo *p)
{
	int	i;
	int	t;

	i = -1;
	while (i++ < p->param->philo_nb)
		pthread_create(&p[i].thread, NULL, &routine, &p[i]);
	i = -1;
	t = current_time();
	while (i++ < p->param->philo_nb)
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
	while (i++ < param->philo_nb)
		pthread_mutex_init(p[i].forkl, NULL);
	pthread_mutex_init(param->print, NULL);
	create_threads(p);
}

//parse
void	init_philo(t_philo *p, t_data *param)
{
	int	i;

	i = -1;
	while (i++ < param->philo_nb)
	{
		p[i].start = 0;
		p[i].id = i + 1;
		p[i].thread = 0;
		p[i].meal = 0;
		p[i].forkl = &param->fork[i];
		if (p[i].id == param->philo_nb)
			p[i].forkr = &param->fork[0];
		else
			p[i].forkr = &param->fork[i + 1];
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
	return (param);
	param->dead_time = ft_atoi(argv[2]);
	param->eat_time = ft_atoi(argv[3]);
	param->sleep_time = ft_atoi(argv[4]);
	param->check_sum = 0;
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

//errors
void	error_output(void)
{
	printf("Wrong input!\n");
	printf("Following args are needed or allowed\n");
	printf("number_of_philosophers time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
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

//chek
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

//chek
int	arg_is_number(char *argv)
{
	int	i;

	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

//chek
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
		|| (ft_atoi(argv[5]) <= 0 && argv[5]))
		return (0);
	return (1);
}

//main
int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if ((argc != 5 && argc != 6 || !check_input(argv)))
	{
		error_output();
		exit (0);
	}
	philo = malloc (sizeof(t_philo) * ft_atoi(argv[1]));
	data = parse_data(*argv);
	init_philo(philo, data);
	init_threads(philo, data);
}
