#include "../../incl/minishell.h"

t_token	*ft_new_token(char *content, int flag)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
	new->flag = flag;
	new->next = NULL;
	return (new);
}
