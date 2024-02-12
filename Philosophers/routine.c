/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:41:20 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/15 17:29:33 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->main->death);
	while (i < philo->main->n_philo && philo->main->philo_died == 0)
	{
		pthread_mutex_unlock(&philo->main->death);
		pthread_mutex_lock(&philo->main->death);
		if (ft_time() - philo->last_eat >= philo->main->t_die)
		{
			philo->main->philo_died = 1;
			pthread_mutex_lock(&philo->main->print);
			printf("%ld		philo %d died\n", ft_time() - philo->main->start, \
			philo->i + 1);
			pthread_mutex_unlock(&philo->main->print);
			pthread_mutex_unlock(&philo->main->death);
			return (1);
		}
		pthread_mutex_unlock(&philo->main->death);
		i++;
		pthread_mutex_lock(&philo->main->death);
	}
	pthread_mutex_unlock(&philo->main->death);
	return (0);
}

int	ft_check_eat(t_philo *philo)
{
	pthread_mutex_unlock(&philo->main->eat);
	if (philo->eat == philo->main->nb_eat)
	{
		pthread_mutex_lock(&philo->main->eat);
		philo->main->all_eat++;
		pthread_mutex_unlock(&philo->main->eat);
	}
	pthread_mutex_lock(&philo->main->eat);
	if (philo->main->all_eat >= philo->main->n_philo)
		return (1);
	return (0);
}

static int	ft_life(t_philo *philo)
{
	if (ft_death(philo) == 1)
	{
		ft_lock_mutex(philo);
		return (1);
	}
	pthread_mutex_lock(&philo->main->forks[philo->r_fork]);
	if (philo->main->fork_value[philo->r_fork] == 0)
	{
		pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
		ft_eat(philo);
	}
	else
	{
		pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
		usleep(100);
	}
	ft_lock_mutex(philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->i % 2 == 0)
		ft_usleep(philo->main->t_eat * 0.5, philo);
	if (philo->i == philo->main->n_philo - 1 && philo->main->n_philo % 2 != 0)
		usleep(100);
	ft_lock_mutex(philo);
	while (philo->main->philo_died == 0 && \
	philo->main->all_eat < philo->main->n_philo)
	{
		ft_unlock_mutex(philo);
		if (ft_life(philo) == 1)
			break ;
	}
	ft_unlock_mutex(philo);
	return (NULL);
}
