/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:52:05 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/24 08:34:13 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game {
	char	*mapall;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player;
	void	*space;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		players;
	int		gameover;
	int		steps;
	int		score;
	int		max_score;
}				t_game;

void	img_display(t_game *map);
void	map_display(t_game *map, int i);
void	window_start(t_game *map);
void	error_final(char *str, t_game *game);
int		format_check(char *map_file);
void	init_values(t_game *game);
void	w_key(t_game *map);
void	s_key(t_game *map);
void	d_key(t_game *map);
void	a_key(t_game *map);
int		ft_key_hook(int keycode, t_game *map);
char	*ft_strjoin_util(char *s1, char *s2);
void	check_map(t_game *map);
int		check_line_util(t_game *map, char **line, int i);
int		check_line(t_game *map, char **line, int fd);
void	map_parsing(int fd, t_game *game);
void	start_game(char *map, t_game *game);
void	free_list(t_game *map);
int		close_window(t_game *map);
void	error_message(int i, t_game *game);

#endif