/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:37:54 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/15 14:31:25 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_main *main)
{
	int		i;

	i = 0;
	while (i < main->n_philo)
	{
		if (pthread_create(&main->philo[i].t, NULL, &routine, \
		&main->philo[i]) != 0)
		{
			printf("Failed to create thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < main->n_philo)
	{
		if (pthread_join(main->philo[i].t, NULL) != 0)
		{
			printf("Failed to join threads\n");
			return (1);
		}
		i++;
	}
	return (0);
}

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
	free(main->fork_value);
	pthread_mutex_destroy(&main->print);
	pthread_mutex_destroy(&main->death);
	pthread_mutex_destroy(&main->eat);
}
