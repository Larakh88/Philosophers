/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:28:31 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/25 14:32:33 by lel-khou         ###   ########.fr       */
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
		main->philo[j].main = main;
		j++;
	}
}

int	ft_init(t_main *main, char **argv, int argc)
{
	main->n_philo = ft_atoi(argv[1]);
	main->t_die = ft_atoi(argv[2]);
	main->t_eat = ft_atoi(argv[3]);
	main->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		main->nb_eat = ft_atoi(argv[5]);
	main->philo = malloc(sizeof(t_philo) * main->n_philo);
	if (!main->philo)
		return (1);
	if (mutex_init(main) == 1)
	{
		free(main->philo);
		return (1);
	}
	philo_init(main);
	return (0);
}
