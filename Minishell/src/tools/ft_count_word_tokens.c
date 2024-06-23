#include "../../incl/minishell.h"

int	ft_count_word_tokens(t_data *data)
{
	t_token	*tmp;
	int		i;

	tmp = data->tokens;
	if (!tmp)
		return (0);
	i = 0;
	while (tmp != NULL && tmp->flag != T_PIPE)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
