/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:06 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/07 21:01:23 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->n_philo)
	{
		pthread_mutex_destroy(&(main->forks[i]));
		i++;
	}
	free(main->forks);
	free(main->philo);
	pthread_mutex_destroy(&main->print);
	pthread_mutex_destroy(&main->death);
	pthread_mutex_destroy(&main->eat);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (ft_error(argc, argv) == 1)
		return (1);
	if (ft_init(&main, argv, argc) == 1)
		return (1);
	main.start = ft_time();
	create_threads(&main);
	return (0);
}
