/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:52:55 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/26 14:48:00 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//parse
t_data	*parse_data(char	**argv)
{
	t_data	*param;

	param = malloc(sizeof(t_data));
	if (param == NULL)
		return (NULL);
	param->finished = 0;
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
}
