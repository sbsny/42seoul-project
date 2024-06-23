/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:14 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:11:10 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<sys/time.h>
# include	<pthread.h>
# include	<stdbool.h>
# include	<stdio.h>

typedef enum e_status
{
	TAKEN_FORK	=	1,
	EATING		=	2,
	SLEEPING	=	3,
	THINKING	=	4,
	DEAD		=	5,
}	t_status;

typedef struct s_args
{
	int		philos_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_to_eat;
	long	start_time;
}	t_args;

typedef struct s_philo
{
	t_args			*args;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
	pthread_t		philo_p;
	long			last_meal;
	int				id;
	int				meals_eaten;
	bool			*alive;
}	t_philo;

void	*actions(void *ph);
void	output(t_philo *ph, int state);
int		join_destr(t_philo *philo, int ph);
t_philo	*alloc_args(t_args *args);
int		free_data(t_philo *philo);
int		ft_sleep(long s_time, t_philo *ph);
long	get_time(void);

#endif