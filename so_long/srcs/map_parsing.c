/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:46:36 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 09:25:16 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strjoin_util(char *s1, char *s2)
{
	char	*new;
	char	*tmp;

	if (!s1)
		return (ft_strtrim(s2, "\n"));
	tmp = ft_strjoin(s1, s2);
	new = ft_strtrim(tmp, "\n");
	free(tmp);
	return (new);
}

void	check_map(t_game *map)
{
	int	i;
	int	j;

	i = map->width;
	while (i > -1)
	{
		if (map->mapall[i] != '1')
			error_final("Not surrounded by correct size of the wall\n", map);
		i--;
	}
	i = map->width;
	j = ft_strlen(map->mapall);
	while (i > -1)
	{
		if (map->mapall[j - 1] != '1')
			error_final("Not surrounded by correct size of the wall\n", map);
		j--;
		i--;
	}
}

int	check_line_util(t_game *map, char **line, int i)
{
	if ((*line)[i] != '1')
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
			&& (*line)[i] != 'E' && (*line)[i] != 'P' && (*line)[i] != '\0'
			&& (*line)[i] != '\n')
		{
			free(*line);
			error_final("Wrong Character Type\n", map);
		}
		free(*line);
		error_final("Not surrounded by correct size of the wall\n", map);
	}
	return (1);
}

int	check_line(t_game *map, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = check_line_util(map, line, 0);
	while ((*line)[i + 1] != '\n' && (*line)[i + 1])
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
			&& (*line)[i] != 'E' && (*line)[i] != 'P')
		{
			free(*line);
			error_final("Wrong Character Type\n", map);
		}
		i++;
	}
	i = i + check_line_util(map, line, i);
	tmp = map->mapall;
	map->mapall = ft_strjoin_util(tmp, *line);
	free(tmp);
	free(*line);
	if (i != map->width && map->width != 0)
		error_final("Not surrounded by correct size of the wall\n", map);
	*line = get_next_line(fd);
	map->height++;
	return (i);
}

void	map_parsing(int fd, t_game *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_final("Nothing in files\n", game);
	while (line)
		game->width = check_line(game, &line, fd);
	close(fd);
	check_map(game);
	i = 0;
	fd = 0;
	while (game->mapall[fd])
	{
		if (game->mapall[fd] == 'C')
			game->max_score++;
		if (game->mapall[fd] == 'P')
			game->players++;
		if (game->mapall[fd] == 'E')
			i++;
		fd++;
	}
	error_message(i, game);
}
