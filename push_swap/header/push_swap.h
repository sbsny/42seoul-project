/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 05:11:21 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/23 02:04:50 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*stack;
	int		top;
}				t_stack;

typedef struct s_piv_cnt
{
	int		big;
	int		small;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}				t_piv_cnt;

void			error(void);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s);
int				check_dup(int *stack, int size);
int				malloc_tri_free(char ***str);
int				count(char ***arg);
int				*setting_stack(char ***arg, int size);
char			***parsing_arg(char **argv, int argc);
long long		ft_atoi(const char *str);
int				s(t_stack *stack);
int				p(t_stack *pop, t_stack *push);
int				r_rr(int i, t_stack *stack);
void			operation(char *str, t_stack *a, t_stack *b);
void			operation_2(char *str, t_stack *a, t_stack *b);
int				is_sort(t_stack *stack, int size, int mod);
void			sort_3(t_stack *a, t_stack *b);
void			sort_4(t_stack *a, t_stack *b);
void			sort_5(t_stack *a, t_stack *b);
void			bubble_sort(int *array, int size);
int				sort_b(t_stack *a, t_stack *b, int size);
int				sort_a(t_stack *a, t_stack *b, int size);
void			sort_and_pivot(t_stack *s, int size, t_piv_cnt *piv, int mod);
int				a_to_b(t_stack *a, t_stack *b, int size);
void			div_a_move(t_stack *a, t_stack *b, int size, t_piv_cnt *piv);
int				b_to_a(t_stack *a, t_stack *b, int size);
void			div_b_move(t_stack *a, t_stack *b, int size, t_piv_cnt *piv);
int				init_stack(t_stack *a, t_stack *b, int size, char ***arg);
void			push_swap(t_stack *a, t_stack *b, int size);

#endif
