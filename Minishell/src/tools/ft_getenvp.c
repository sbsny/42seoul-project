#include "../../incl/minishell.h"

t_envp	*ft_getenvp(t_data *data, char *find)
{
	t_envp	*tmp;

	tmp = data->envp;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (ft_strcmp(tmp->key, find) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
