/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:27:09 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 12:00:44 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	int	i;
	int	*stack;

	i = a->top;
	stack = a->stack;
	if (stack[i] < stack[i - 2] && stack[i - 1] > stack[i - 2])
	{
		operation("sa", a, b);
		operation("ra", a, b);
	}
	else if (stack[i] > stack[i - 1] && stack[i] < stack[i - 2])
		operation("sa", a, b);
	else if (stack[i] < stack[i - 1] && stack[i] > stack[i - 2])
		operation("rra", a, b);
	else if (stack[i] > stack[i - 1] && stack[i - 1] < stack[i - 2])
		operation("ra", a, b);
	else if (stack[i] > stack[i - 1] && stack[i - 1] > stack[i - 2])
	{
		operation("ra", a, b);
		operation("sa", a, b);
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	if (!is_sort(a, 4, 0))
	{
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		operation("pb", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		operation("pb", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1] && \
			b->stack[b->top] < b->stack[b->top - 1])
			operation("ss", a, b);
		else if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		else if (b->stack[b->top] < b->stack[b->top - 1])
			operation("sb", a, b);
		operation("pa", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		operation("pa", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	i;
	int	array[5];

	if (!is_sort(a, 5, 0))
	{
		i = -1;
		while (++i < 5)
			array[i] = a->stack[a->top - i];
		bubble_sort(array, 5);
		while (i-- > 0)
		{
			if (a->stack[a->top] <= array[1])
				operation("pb", a, b);
			else
				operation("ra", a, b);
		}
		sort_3(a, b);
		if (b->stack[b->top] < b->stack[b->top - 1])
			operation("sb", a, b);
		operation("pa", a, b);
		operation("pa", a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	if (is_sort(a, size, 0))
		return ;
	if (size == 2)
	{
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
	}
	else if (size == 3)
		sort_3(a, b);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
		a_to_b(a, b, size);
	free(a->stack);
	a->stack = NULL;
	free(b->stack);
	b->stack = NULL;
}

int	main(int argc, char **argv)
{
	char	***arg;
	int		size;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	arg = parsing_arg(argv, argc);
	if (!arg)
		error();
	size = count(arg);
	init_stack(&a, &b, size, arg);
	push_swap(&a, &b, size);
	return (0);
}
