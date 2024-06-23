/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:24:35 by seonyun           #+#    #+#             */
/*   Updated: 2022/12/23 01:24:35 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 1)
	{
		printf("minishell: %s: No such file or directory\n", argv[1]);
		return (EXIT_FAILURE);
	}
	(void) argv;
	init_shell_env(&data, env);
	while (data.exit_minishell == false)
	{
		ft_signals(MAIN_PROCESS);
		track_history(&data);
		lex_input(&data);
		if (data.lex_error == false)
		{
			parse_tokens(&data);
			if (data.parse_error == false)
				execute_tokens(&data);
		}
		free_tokens(&data);
	}
	free_all_resources(&data);
	return (g_exit_code);
}
