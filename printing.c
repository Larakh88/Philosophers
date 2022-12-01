/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:41:15 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/29 16:47:08 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	gettimeofday(&philo->main->end, NULL);
	pthread_mutex_lock(&philo->main->print);
	printf("%ld		philo %d %s %d\n", (ft_time(philo->main->end) - \
	ft_time(philo->main->start)), philo->i + 1, str, philo->l_fork);
	pthread_mutex_unlock(&philo->main->print);
}
