/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:19:07 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/14 13:44:05 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483647 && sign == 1)
			return (-1);
		if (res > 2147483648 && sign == -1)
			return (0);
		i++;
	}	
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_time(void)
{
	struct timeval	time;
	long			t;

	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (t);
}

void	ft_usleep(int time, t_philo *philo)
{
	long	t;

	t = ft_time();
	while (ft_time() - t < time && philo->main->philo_died == 0 && \
	philo->main->all_eat < philo->main->n_philo)
		usleep(20);
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->main->print);
	if (philo->main->philo_died == 0 && \
	philo->main->all_eat < philo->main->n_philo)
	{
		printf("%ld		philo %d %s\n", ft_time() - philo->main->start, \
		philo->i + 1, str);
	}
	pthread_mutex_unlock(&philo->main->print);
}
