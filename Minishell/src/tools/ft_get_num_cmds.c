#include "../../incl/minishell.h"

int	ft_get_num_cmds(t_data *data)
{
	t_token	*tmp;
	int		i;

	tmp = data->tokens;
	i = 1;
	while (tmp != NULL)
	{
		if (tmp->flag == T_PIPE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
