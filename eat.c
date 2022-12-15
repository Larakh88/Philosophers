/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:30:49 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/15 17:22:26 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_sleep_think(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->main->t_sleep, philo);
	ft_print(philo, "is thinking");
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->forks[philo->l_fork]);
	philo->main->fork_value[philo->l_fork] = 1;
	ft_print(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->main->forks[philo->l_fork]);
	pthread_mutex_lock(&philo->main->forks[philo->r_fork]);
	philo->main->fork_value[philo->r_fork] = 1;
	ft_print(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
	ft_print(philo, "is eating");
	philo->last_eat = ft_time();
	philo->eat++;
	pthread_mutex_lock(&philo->main->eat);
	ft_check_eat(philo);
	pthread_mutex_unlock(&philo->main->eat);
	ft_usleep(philo->main->t_eat, philo);
	pthread_mutex_lock(&philo->main->forks[philo->r_fork]);
	philo->main->fork_value[philo->r_fork] = 0;
	pthread_mutex_unlock(&philo->main->forks[philo->r_fork]);
	pthread_mutex_lock(&philo->main->forks[philo->l_fork]);
	philo->main->fork_value[philo->l_fork] = 0;
	pthread_mutex_unlock(&philo->main->forks[philo->l_fork]);
	ft_sleep_think(philo);
}
