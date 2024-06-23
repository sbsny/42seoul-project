/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 07:49:33 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 08:35:51 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_values(t_game *game)
{
	game->mapall = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->item = NULL;
	game->player = NULL;
	game->space = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->players = 0;
	game->gameover = 0;
	game->steps = 0;
	game->score = 0;
	game->max_score = 0;
}

int	format_check(char *map_name)
{
	int		i;
	char	*extension_name;

	extension_name = ".ber";
	i = 0;
	while (ft_strlen(map_name) != 4 && map_name)
		map_name++;
	if (!map_name || *map_name == '\0')
		return (0);
	while (map_name[i])
	{
		if (map_name[i] != extension_name[i])
			return (0);
		i++;
	}
	return (1);
}

void	window_start(t_game *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx,
			100 * map->width, 100 * map->height, "so_long subject");
	img_display(map);
	map_display(map, 0);
	mlx_hook(map->win, 17, 0, close_window, map);
	mlx_key_hook(map->win, ft_key_hook, map);
	mlx_loop(map->mlx);
}

void	start_game(char *map, t_game *game)
{
	int		fd;

	if (!format_check(map))
		error_final("Wrong map format\n", game);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_final("File does not exist\n", game);
	map_parsing(fd, game);
	window_start(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_values(&game);
	if (argc == 2)
	{
		start_game(argv[1], &game);
	}
	error_final("Argument Number Error\n", &game);
	return (0);
}
