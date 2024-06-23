#include "../../incl/minishell.h"

int	env(t_data *data)
{
	t_envp	*tmp;

	if (data->exec->cmd[1])
	{
		print_error(ENV_ERROR);
		return (CMD_NOT_FOUND);
	}
	tmp = data->envp;
	while (tmp != NULL)
	{
		if (tmp->key[0] && tmp->equal == 1)
		{
			printf("%s=%s\n", tmp->key, tmp->val);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
