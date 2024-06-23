#include "../../incl/minishell.h"

int	print_list(t_token *data)
{
	t_token	*tmp;
	int		len;

	len = 0;
	tmp = data;
	while (tmp != NULL)
	{
		len++;
		printf("%s\nflag = %i\n", tmp->content, tmp->flag);
		if (tmp->join)
			printf("join = true\n");
		else
			printf("join = false\n");
		tmp = tmp->next;
	}
	return (len);
}
