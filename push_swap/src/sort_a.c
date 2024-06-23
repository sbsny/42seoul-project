/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:16:21 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/06 11:44:21 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a(t_stack *a, t_stack *b, int size)
{
	if (size == 4)
		sort_4(a, b);
	else if (size >= 2)
	{
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		if (size == 3 && !is_sort(a, size, 0))
		{
			operation("ra", a, b);
			operation("sa", a, b);
			operation("rra", a, b);
			if (a->stack[a->top] > a->stack[a->top - 1])
				operation("sa", a, b);
		}
	}
	return (1);
}

void	div_a_move(t_stack *a, t_stack *b, int size, t_piv_cnt *piv_cnt)
{
	while (size-- > 0)
	{
		if (a->stack[a->top] > piv_cnt->big)
		{
			operation("ra", a, b);
			piv_cnt->ra++;
		}
		else if (a->stack[a->top] <= piv_cnt->small)
		{
			operation("pb", a, b);
			piv_cnt->pb++;
		}
		else
		{
			operation("pb", a, b);
			piv_cnt->pb++;
			operation("rb", a, b);
			piv_cnt->rb++;
		}
	}
}

int	a_to_b(t_stack *a, t_stack *b, int size)
{
	t_piv_cnt	piv_cnt;
	int			rrr_size;

	if (size <= 4)
		return (sort_a(a, b, size));
	piv_cnt = (t_piv_cnt){0, 0, 0, 0, 0, 0};
	sort_and_pivot(a, size, &piv_cnt, 0);
	div_a_move(a, b, size, &piv_cnt);
	rrr_size = piv_cnt.rb;
	while (rrr_size-- > 0)
		operation_2("rrr", a, b);
	a_to_b(a, b, piv_cnt.ra);
	b_to_a(a, b, piv_cnt.rb);
	b_to_a(a, b, piv_cnt.pb - piv_cnt.rb);
	return (1);
}
