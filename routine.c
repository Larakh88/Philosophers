/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:41:20 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/01 13:11:54 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *philo)
{
	long long	diff;

	pthread_mutex_lock(&philo->main->death);
	gettimeofday(&philo->main->end, NULL);
	philo->main->t_current = ft_time(philo->main->end);
	diff = philo->main->t_current - philo->main->t_start;
	pthread_mutex_unlock(&philo->main->death);
	if (diff >= philo->main->t_die)
	{
		ft_print(philo, "died");
		pthread_detach(philo->t);
		return (1);
	}
	return (0);
}

static void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	usleep(philo->main->t_sleep * 1000);
}

static void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->i % 2 == 0)
		usleep(philo->main->t_eat * 500);
	while (ft_death(philo) != 1)
	{
		pthread_mutex_lock(&philo->main->forks[philo->l_fork]);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->main->forks[philo->r_fork]);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		usleep(philo->main->t_eat * 1000);
		philo->eat++;
		pthread_mutex_unlock(&philo->main->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
		ft_sleep(philo);
		ft_think(philo);
	}
	exit (0);
}
