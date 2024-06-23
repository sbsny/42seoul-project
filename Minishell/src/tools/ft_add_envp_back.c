#include "../../incl/minishell.h"

void	ft_add_envp_back(t_envp **lst, t_envp *new)
{
	t_envp	*tmp;

	tmp = NULL;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
