#include "../../incl/minishell.h"

static int	count_hdoc_files(t_data *data)
{
	t_token	*tmp;
	int		i;

	tmp = data->tokens;
	if (!tmp)
		return (0);
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->flag == T_HEREDOC)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	parse_tokens(t_data *data)
{
	int	cnt;

	data->parse_error = false;
	init_fd(data);
	check_multiple_pipes(data);
	if (data->parse_error == true)
		return ;
	merge_joinable_tokens(data);
	merge_redirections(data);
	if (data->parse_error == true)
		return ;
	cnt = count_hdoc_files(data);
	if (cnt == 0)
		return ;
	else
	{
		data->fd->hdoc = malloc(sizeof(char *) * (cnt + 1));
		data->fd->hdoc[cnt] = NULL;
		parse_hdocs(data);
	}
}
