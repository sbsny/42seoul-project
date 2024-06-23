#include "../../incl/minishell.h"

int	ft_get_builtin(t_data *data)
{
	if (ft_strcmp(data->exec->cmd[0], data->builtins->names[0]) == 0)
		return (0);
	if (ft_strcmp(data->exec->cmd[0], data->builtins->names[1]) == 0)
		return (1);
	if (ft_strcmp(data->exec->cmd[0], data->builtins->names[2]) == 0)
		return (2);
	if (ft_strcmp(data->exec->cmd[0], data->builtins->names[3]) == 0)
		return (3);
	if (ft_strcmp(data->exec->cmd[0], data->builtins->names[4]) == 0)
		return (4);
	if (ft_strcmp(data->exec->cmd[0], data->builtins->names[5]) == 0)
		return (5);
	if (ft_strcmp(data->exec->cmd[0], data->builtins->names[6]) == 0)
		return (6);
	return (-1);
}
