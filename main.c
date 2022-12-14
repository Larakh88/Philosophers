/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:06 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/14 10:54:25 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_one_philo(char **argv)
{
	long	time;
	int		sleep;

	time = ft_time();
	sleep = ft_atoi(argv[2]) * 1000;
	printf("%ld		philo 1 has taken a fork\n", ft_time() - time);
	usleep(sleep);
	printf("%ld		philo 1 died\n", ft_time() - time);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (ft_error(argc, argv) == 1)
		return (1);
	if (ft_atoi(argv[1]) == 1)
	{
		ft_one_philo(argv);
		return (0);
	}
	if (ft_init(&main, argv, argc) == 1)
		return (1);
	main.start = ft_time();
	if (create_threads(&main) == 1)
		ft_exit(&main);
	ft_exit(&main);
	return (0);
}
