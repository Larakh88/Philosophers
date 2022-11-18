/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:52 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/18 17:52:11 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
#include <string.h>
# include <sys/time.h>

typedef struct s_data
{
	int			n_philo;
	int			n_forks;
	int			t_die;
	int			t_sleep;
	int			t_think;
	int			nb_eat;
	pthread_t	t[200];

}	t_data;

void	*routine(void *arg);
int		ft_atoi(const char *str);

#endif