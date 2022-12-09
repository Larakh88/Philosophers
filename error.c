/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:19 by lel-khou          #+#    #+#             */
/*   Updated: 2022/12/07 16:43:53 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_arg_numb(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong Number of Arguments\n");
		return (1);
	}
	if (ft_arg_numb(argc, argv) == 1)
	{
		printf("Arguments are not all numbers\n");
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) == 0)
	{
		printf("Nb of eats cannot be zero\n");
		return (1);
	}
	return (0);
}
