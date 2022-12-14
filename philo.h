/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:52 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/14 22:29:06 by lel-khou         ###   ########.fr       */
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
	long			last_eat;
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
	int				all_eat;
	long			start;
	int				philo_died;
	int				*fork_value;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	eat;
}	t_main;

int		ft_error(int argc, char **argv);
int		ft_init(t_main *main, char **argv, int argc);
int		create_threads(t_main *main);
void	*routine(void *arg);
int		ft_death(t_philo *philo);
void	ft_exit(t_main *main);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
long	ft_time(void);
void	ft_usleep(int time, t_philo *philo);
void	ft_print(t_philo *philo, char *str);
void	ft_unlock_mutex(t_philo *philo);
void	ft_lock_mutex(t_philo *philo);
void	start_condition(t_philo *philo);

#endif