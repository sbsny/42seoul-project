#include "../../incl/minishell.h"

void	ft_lstclear(t_envp **lst)
{
	t_envp	*tmp;

	if ((!lst) || (!*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
