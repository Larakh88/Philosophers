/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:41:20 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/13 16:09:21 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->death);
	if (ft_time() - philo->last_eat >= philo->main->t_die)
	{
		philo->main->philo_died = 1;
		pthread_mutex_unlock(&philo->main->death);
		ft_print(philo, "died");
		return (1);
	}
	pthread_mutex_unlock(&philo->main->death);
	return (0);
}

static int	ft_check_eat(t_philo *philo)
{
	if (philo->eat == philo->main->nb_eat)
	{
		pthread_mutex_lock(&philo->main->eat);
		philo->main->all_eat++;
		pthread_mutex_unlock(&philo->main->eat);
	}
	if (philo->main->all_eat >= philo->main->n_philo)
		return (1);
	return (0);
}

static void	ft_sleep_think(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->main->t_sleep, philo);
	ft_print(philo, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->i % 2 == 0)
		ft_usleep(philo->main->t_eat * 0.5, philo);
	while (1)
	{
		ft_death(philo);
		if (philo->main->philo_died == 1)
			break ;
		if (philo->main->fork_value[philo->l_fork] == 0 && philo->main->fork_value[philo->r_fork] == 0)
		{
			pthread_mutex_lock(&philo->main->forks[philo->l_fork]);
			philo->main->fork_value[philo->l_fork] = 1;
			ft_print(philo, "has taken a fork left");
			pthread_mutex_lock(&philo->main->forks[philo->r_fork]);
			philo->main->fork_value[philo->r_fork] = 1;
			ft_print(philo, "has taken a fork right");
			ft_print(philo, "is eating");
			philo->last_eat = ft_time();
			philo->eat++;
			if (ft_check_eat(philo) == 1)
				break ;
			ft_usleep(philo->main->t_eat, philo);
			philo->main->fork_value[philo->r_fork] = 0;
			pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
			philo->main->fork_value[philo->l_fork] = 0;
			pthread_mutex_unlock(&philo->main->forks[philo->l_fork]);
			ft_sleep_think(philo);
		}
		else
			usleep(100);
	}
	return (NULL);
}
