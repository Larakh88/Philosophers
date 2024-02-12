/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:28:31 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/13 16:09:18 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutex_init(t_main *main)
{
	int	i;

	i = 0;
	main->forks = malloc(sizeof(pthread_mutex_t) * main->n_philo);
	while (i < main->n_philo)
	{
		if (pthread_mutex_init(&(main->forks[i]), NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(main->print), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(main->death), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(main->eat), NULL) != 0)
		return (1);
	return (0);
}

static void	philo_init(t_main *main)
{
	int	j;

	j = 0;
	while (j < main->n_philo)
	{
		main->philo[j].i = j;
		main->philo[j].eat = 0;
		main->philo[j].r_fork = j;
		main->philo[j].l_fork = (j + 1);
		if (j == main->n_philo - 1)
			main->philo[j].l_fork = 0;
		main->philo[j].last_eat = ft_time();
		main->philo[j].main = main;
		j++;
	}
}

static int	forks_init(t_main *main)
{
	int	i;

	i = 0;
	main->fork_value = malloc(sizeof(int) * main->n_philo);
	if (!main->fork_value)
		return (1);
	while (i < main->n_philo)
	{
		main->fork_value[i] = 0;
		i++;
	}
	return (0);
}

static void	main_init(t_main *main, char **argv, int argc)
{
	main->n_philo = ft_atoi(argv[1]);
	main->t_die = ft_atoi(argv[2]);
	main->t_eat = ft_atoi(argv[3]);
	main->t_sleep = ft_atoi(argv[4]);
	main->philo_died = 0;
	main->all_eat = 0;
	if (argc == 6)
		main->nb_eat = ft_atoi(argv[5]);
	else
		main->nb_eat = -1;
}

int	ft_init(t_main *main, char **argv, int argc)
{
	main_init(main, argv, argc);
	if (forks_init(main) == 1)
		return (1);
	main->philo = malloc(sizeof(t_philo) * main->n_philo);
	if (!main->philo)
	{
		free(main->fork_value);
		return (1);
	}
	if (mutex_init(main) == 1)
	{
		free(main->philo);
		free(main->fork_value);
		return (1);
	}
	philo_init(main);
	return (0);
}
