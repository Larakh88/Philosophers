/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:41:20 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/07 21:01:19 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *philo)
{
	long	diff;

	diff = ft_time() - philo->last_eat;
	if (diff >= philo->main->t_die)
	{
		pthread_mutex_lock(&philo->main->death);
		ft_print(philo, "died");
		philo->main->philo_died = 1;
		ft_exit(philo->main);
	}
	return (0);
}

static void	ft_check_eat(t_philo *philo)
{
	if (philo->eat == philo->main->nb_eat)
	{
		pthread_mutex_lock(&philo->main->eat);
		philo->main->all_eat++;
		pthread_mutex_unlock(&philo->main->eat);
	}
	if (philo->main->all_eat == philo->main->n_philo)
		ft_exit(philo->main);
}

static void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->main->t_sleep, philo);
}

static void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking");
	usleep(1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->i % 2 == 0)
		ft_usleep(philo->main->t_eat * 0.5, philo);
	while (ft_death(philo) == 0)
	{
		pthread_mutex_lock(&philo->main->forks[philo->l_fork]);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->main->forks[philo->r_fork]);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		philo->last_eat = ft_time();
		philo->eat++;
		ft_check_eat(philo);
		ft_usleep(philo->main->t_eat, philo);
		pthread_mutex_unlock(&philo->main->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
