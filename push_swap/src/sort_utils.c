/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:15:53 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 10:40:26 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
		}
	}
}

int	is_sort(t_stack *stack, int size, int type)
{
	int	idx;
	int	bottom;

	idx = stack->top + 1;
	bottom = stack->top - size + 1;
	if (type == 0)
	{
		while (--idx > bottom)
			if (stack->stack[idx] > stack->stack[idx - 1])
				return (0);
	}
	else if (type == 1)
	{
		while (--idx > bottom)
			if (stack->stack[idx] < stack->stack[idx - 1])
				return (0);
	}
	return (1);
}

void	sort_and_pivot(t_stack *stack, int size, t_piv_cnt *pivot, int type)
{
	int	i;
	int	div;
	int	*array;

	i = -1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		exit(1);
	while (++i < size)
		array[i] = stack->stack[stack->top - i];
	bubble_sort(array, size);
	div = size / 3;
	if (size % 3 == 2)
		div++;
	if (type == 0)
	{
		pivot->small = array[(size - 1) - (div * 2)];
		pivot->big = array[(size - 1) - div];
	}
	else if (type == 1)
	{
		pivot->small = array[div];
		pivot->big = array[div * 2];
	}
	free(array);
}
