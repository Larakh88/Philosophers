/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:06 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/18 17:52:09 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data thread)
{
	int	i;
	int	*a;

	i = 0;
	while (i < thread.n_philo)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&thread.t[i], NULL, &routine, a) != 0)
			printf("Failed to create thread\n");
		i++;
	}
	i = 0;
	while (i < thread.n_philo)
	{
		if (pthread_join(thread.t[i], NULL) != 0)
			printf("Failed to join threads\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	thread;

	(void)argc;
	thread.n_philo = ft_atoi(argv[1]);
	memset(thread.t, 0, sizeof(pthread_t));
	create_threads(thread);
}

// int	main(void)
// {
// 	struct timeval	start;
// 	struct timeval	end;

// 	gettimeofday(&start, NULL);
// 	usleep(1000000);
// 	gettimeofday(&end, NULL);
// 	printf("wait time is %ld\n", (end.tv_sec * 1000 + end.tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000));
// 	return (0);
// }
