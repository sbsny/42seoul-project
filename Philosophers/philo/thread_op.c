/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:37 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:25:08 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setting_args(t_philo *ph, t_args *args, int i)
{
	while (i < args->philos_nbr)
	{
		ph[i].right_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!ph[i].right_fork || pthread_mutex_init(ph[i].right_fork, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < args->philos_nbr)
	{
		ph[i].id = i + 1;
		ph[i].left_fork = ph[(i + 1) % args->philos_nbr].right_fork;
		ph[i].alive = ph[0].alive;
		ph[i].print = ph[0].print;
		ph[i].death = ph[0].death;
		ph[i].args = args;
		ph[i].last_meal = 0;
		ph[i].meals_eaten = 0;
		if (pthread_create(&ph[i].philo_p, NULL, &actions, (void *)&ph[i]))
			return (1);
		i++;
	}
	return (0);
}

t_philo	*alloc_args(t_args *args)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * (args->philos_nbr));
	philo->alive = (bool *)malloc(sizeof(bool));
	philo->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo || !philo->alive || !philo->print || !philo->death)
		return (NULL);
	*(philo->alive) = true;
	if (pthread_mutex_init(philo->print, NULL))
		return (NULL);
	if (pthread_mutex_init(philo->death, NULL))
		return (NULL);
	if (setting_args(philo, args, 0))
		return (NULL);
	return (philo);
}

int	join_destr(t_philo *philo, int ph)
{
	int		i;

	i = 0;
	while (i < ph)
	{
		if (pthread_join(philo[i].philo_p, NULL))
			return (1);
		pthread_mutex_destroy(philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(philo->print);
	pthread_mutex_destroy(philo->death);
	return (0);
}

void	output(t_philo *ph, int status)
{
	pthread_mutex_lock(ph->print);
	printf("%ld\t", get_time() - ph->args->start_time);
	printf("%d", ph->id);
	if (status == TAKEN_FORK)
		printf("\thas taken a fork\n");
	else if (status == EATING)
		printf("\tis eating\n");
	else if (status == SLEEPING)
		printf("\tis sleeping\n");
	else if (status == THINKING)
		printf("\tis thinking\n");
	else if (status == DEAD)
		printf("\tdied\n");
	pthread_mutex_unlock(ph->print);
}
