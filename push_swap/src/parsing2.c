/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:55:10 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/25 01:23:53 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(char ***arg)
{
	int	i;
	int	j;
	int	cnt;

	i = -1;
	cnt = 0;
	while (arg[++i])
	{
		j = -1;
		while (arg[i][++j])
			cnt++;
	}
	return (cnt);
}

int	*free_and_return(int *stack)
{
	free(stack);
	stack = NULL;
	return (0);
}

int	*setting_stack(char ***arg, int size)
{
	int	*stack;
	int	i[4];

	stack = (int *)malloc(sizeof(int) * size);
	if (!stack)
		return (0);
	i[0] = -1;
	i[2] = size;
	i[3] = 0;
	while (arg[++i[0]] && !i[3])
	{
		i[1] = -1;
		while (arg[i[0]][++i[1]] && !i[3])
		{
			if (ft_atoi(arg[i[0]][i[1]]) == 2147483648)
				i[3] = 1;
			else
				stack[--i[2]] = (int)ft_atoi(arg[i[0]][i[1]]);
		}
	}
	malloc_tri_free(arg);
	if (!check_dup(stack, size) || i[3] == 1)
		return (free_and_return(stack));
	return (stack);
}

char	***parsing_arg(char **argv, int argc)
{
	char	***arg;
	int		i;

	arg = (char ***)malloc(sizeof(char **) * argc);
	if (!arg)
		return (0);
	i = -1;
	while (++i < argc - 1)
	{
		arg[i] = ft_split(argv[i + 1]);
		if (!arg[i])
		{
			malloc_tri_free(arg);
			return (NULL);
		}
	}
	arg[i] = 0;
	return (arg);
}

int	init_stack(t_stack *a, t_stack *b, int size, char ***arg)
{
	a->stack = setting_stack(arg, size);
	if (!a->stack)
		error();
	b->stack = (int *)malloc(sizeof(int) * size);
	if (!b->stack)
		error();
	a->top = size - 1;
	b->top = -1;
	return (1);
}
