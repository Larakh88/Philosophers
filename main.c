/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:06 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/01 10:34:28 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (ft_error(argc, argv) == 1)
		return (1);
	if (ft_init(&main, argv, argc) == 1)
		return (1);
	gettimeofday(&main.start, NULL);
	main.t_start = ft_time(main.start);
	create_threads(&main);
	return (0);
}
