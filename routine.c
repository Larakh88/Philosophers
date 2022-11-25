/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:41:20 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/25 16:13:10 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_main *main)
{
	int		i;

	i = 0;
	while (i < main->n_philo)
	{
		if (pthread_create(&main->philo[i].t, NULL, &routine, \
		&main->philo[i]) != 0)
			printf("Failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < main->n_philo)
	{
		if (pthread_join(main->philo[i].t, NULL) != 0)
			printf("Failed to join threads\n");
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->i % 2 == 0)
		usleep(2000);
	pthread_mutex_lock(&philo->main->forks[philo->l_fork]);
	gettimeofday(&philo->main->end, NULL);
	printf("%ld		philo %d has taken fork %d\n", (philo->main->end.tv_sec * 1000 + philo->main->end.tv_usec / 1000 - philo->main->start.tv_sec * 1000 - philo->main->start.tv_usec / 1000), philo->i + 1, philo->l_fork);
	pthread_mutex_lock(&philo->main->forks[philo->r_fork]);
	printf("%ld		philo %d has taken fork %d\n", (philo->main->end.tv_sec * 1000 + philo->main->end.tv_usec / 1000 - philo->main->start.tv_sec * 1000 - philo->main->start.tv_usec / 1000), philo->i + 1, philo->r_fork);
	pthread_mutex_unlock(&philo->main->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
	return (NULL);
}
