/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:30 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:07:11 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int	ft_sleep(long s_time, t_philo *ph)
{
	long	sleep_start;
	long	current_time;

	sleep_start = get_time();
	current_time = sleep_start;
	while (sleep_start + s_time > current_time)
	{
		if (*(ph->alive) == false)
			return (1);
		if (ph->args->time_to_die < (current_time - ph->args->start_time
				- ph->last_meal))
		{
			pthread_mutex_lock(ph->death);
			output(ph, DEAD);
			*(ph->alive) = false;
			pthread_mutex_unlock(ph->death);
			return (1);
		}
		usleep(150);
		current_time = get_time();
	}
	return (0);
}

int	free_data(t_philo *ph)
{
	int	i;
	int	philo;

	i = 0;
	philo = ph[0].args->philos_nbr;
	while (i < philo)
	{
		if (ph[i].right_fork != NULL)
			free(ph[i].right_fork);
		i++;
	}
	if (ph->alive != NULL)
		free(ph->alive);
	if (ph->print != NULL)
		free(ph->print);
	if (ph->death != NULL)
		free(ph->death);
	if (ph != NULL)
		free(ph);
	return (0);
}
