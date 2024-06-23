/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:44:51 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 01:48:57 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	w_key(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
	if (map->mapall[i - x] != '1' && map->mapall[i - x] != 'E')
	{
		if (map->mapall[i - x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - x] = 'P';
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
}

void	s_key(t_game *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
	if (map->mapall[i + x] != '1' && map->mapall[i + x] != 'E')
	{
		if (map->mapall[i + x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + x] = 'P';
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
}

void	d_key(t_game *map)
{
	int	i;

	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
	if (map->mapall[i + 1] != '1' && map->mapall[i + 1] != 'E')
	{
		if (map->mapall[i + 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + 1] = 'P';
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
}

void	a_key(t_game *map)
{
	int	i;

	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
	if (map->mapall[i - 1] != '1' && map->mapall[i - 1] != 'E')
	{
		if (map->mapall[i - 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - 1] = 'P';
		map->steps++;
		ft_printf("Moves: %d\n", map->steps);
	}
}

int	ft_key_hook(int keycode, t_game *map)
{
	if (keycode == 53)
		map->gameover++;
	else if (keycode == 13)
		w_key(map);
	else if (keycode == 1)
		s_key(map);
	else if (keycode == 2)
		d_key(map);
	else if (keycode == 0)
		a_key(map);
	if (map->gameover > 0)
		close_window(map);
	mlx_clear_window(map->mlx, map->win);
	map_display(map, 0);
	return (0);
}
