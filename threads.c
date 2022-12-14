/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:37:54 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/14 22:31:36 by lel-khou         ###   ########.fr       */
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

void	ft_lock_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->death);
	pthread_mutex_lock(&philo->main->eat);
}

void	ft_unlock_mutex(t_philo *philo)
{
	pthread_mutex_unlock(&philo->main->death);
	pthread_mutex_unlock(&philo->main->eat);
}

void	start_condition(t_philo *philo)
{
	if (philo->i % 2 == 0)
		ft_usleep(philo->main->t_eat * 0.5, philo);
	if (philo->i == philo->main->n_philo - 1 && philo->main->n_philo % 2 != 0)
		usleep(100);
	ft_lock_mutex(philo);
}
