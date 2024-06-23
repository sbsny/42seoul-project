#include "../incl/minishell.h"

void	track_history(t_data *data)
{
	data->input = readline("minishell$ ");
	if (!data->input)
	{
		printf("exit\n");
		free_all_resources(data);
		exit(g_exit_code);
	}
	if (ft_strlen(data->input) != 0)
		add_history(data->input);
}
