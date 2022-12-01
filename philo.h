/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:52 by lel-khou          #+#    #+#             */
/*   Updated: 2022/11/29 16:48:35 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				i;
	int				eat;
	pthread_t		t;
	int				r_fork;
	int				l_fork;
	long long		last_eat;
	struct s_main	*main;
}	t_philo;

typedef struct s_main
{
	int				n_philo;
	t_philo			*philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	long long		t_start;
	long long		t_current;
	struct timeval	start;
	struct timeval	end;
}	t_main;

int		ft_error(int argc, char **argv);
int		ft_init(t_main *main, char **argv, int argc);
void	create_threads(t_main *main);
void	*routine(void *arg);
void	ft_print(t_philo *philo, char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
long	ft_time(struct timeval time);

#endif