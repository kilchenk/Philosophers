/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:52:55 by kilchenk          #+#    #+#             */
/*   Updated: 2023/11/09 18:11:08 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//main
int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if ((argc != 5 && argc != 6) || !check_input(argv))
	{
		error_output();
		return (0);
	}
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	data = parse_data(argv);
	init_philo(philo, data);
	init_threads(philo, data);
	join_threads(philo);
	free_all(philo);
}
