/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:50:31 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 06:37:42 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_message(int i, t_game *game)
{
	if (game->width == game->height)
		error_final("Not rectangular\n", game);
	else if (game->players != 1)
		error_final("Must be one player or contain at least one E or C\n", game);
	else if (i == 0)
		error_final("Must be at least one exit or collectible\n", game);
	else if (game->max_score == 0)
		error_final("Must be at least one collectible\n", game);
}

void	error_final(char *str, t_game *game)
{
	if (game->mapall)
		free(game->mapall);
	write(1, "Error\n", 6);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}
