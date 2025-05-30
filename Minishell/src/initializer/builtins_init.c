#include "../../incl/minishell.h"

static bool	check_names_malloc(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_BUILTINS)
	{
		if (data->builtins->names[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

void	init_builtin_names(t_data *data)
{
	bool	all_names_malloced;

	data->builtins = malloc(sizeof(t_builtins));
	if (!data->builtins)
		exit(EXIT_FAILURE);
	data->builtins->names[0] = ft_strdup("echo");
	data->builtins->names[1] = ft_strdup("cd");
	data->builtins->names[2] = ft_strdup("pwd");
	data->builtins->names[3] = ft_strdup("export");
	data->builtins->names[4] = ft_strdup("unset");
	data->builtins->names[5] = ft_strdup("env");
	data->builtins->names[6] = ft_strdup("exit");
	all_names_malloced = check_names_malloc(data);
	if (all_names_malloced == false)
	{
		free_builtins(data);
		exit(EXIT_FAILURE);
	}
}

void	init_builtin_functions(t_data *data)
{
	data->builtins->funcs[0] = (void *)&echo;
	data->builtins->funcs[1] = (void *)&cd;
	data->builtins->funcs[2] = (void *)&pwd;
	data->builtins->funcs[3] = (void *)&export;
	data->builtins->funcs[4] = (void *)&unset;
	data->builtins->funcs[5] = (void *)&env;
	data->builtins->funcs[6] = (void *)&mini_exit;
}
