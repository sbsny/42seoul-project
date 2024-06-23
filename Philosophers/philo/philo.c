/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:46 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:11:10 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int	checking(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (printf("Error\n"));
	while (av[i])
	{
		j = 0;
		if (ft_atoi(av[i]) <= 0)
			return (printf("Error\n"));
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (printf("Error\n"));
			j++;
		}
		i++;
	}
	return (0);
}

void	parsing(t_args *args, int ac, char **av)
{
	args->start_time = get_time();
	args->philos_nbr = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->meals_to_eat = ft_atoi(av[5]);
	else
		args->meals_to_eat = -1;
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philo;

	if (checking(ac, av))
		return (-1);
	parsing(&args, ac, av);
	philo = alloc_args(&args);
	if (philo == NULL && free_data(philo) == 0)
		return (-1);
	if (args.philos_nbr == 1)
	{
		output(philo, TAKEN_FORK);
		ft_sleep(args.time_to_die, philo);
		output(philo, DEAD);
	}
	if (join_destr(philo, args.philos_nbr) && free_data(philo) == 0)
		return (-1);
	free_data(philo);
	return (0);
}
