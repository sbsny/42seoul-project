#include "../../incl/minishell.h"

void	ft_del_first_token(t_data **data)
{
	t_token	*tmp;

	tmp = (*data)->tokens;
	if (!tmp)
		return ;
	(*data)->tokens = (*data)->tokens->next;
	free(tmp->content);
	tmp->content = NULL;
	free(tmp);
}
