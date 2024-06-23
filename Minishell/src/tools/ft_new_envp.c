#include "../../incl/minishell.h"

t_envp	*ft_new_envp(char *key, char *value)
{
	t_envp	*new;

	new = malloc(sizeof(t_envp));
	if (!new)
		return (NULL);
	new->key = key;
	new->val = value;
	new->next = NULL;
	return (new);
}
