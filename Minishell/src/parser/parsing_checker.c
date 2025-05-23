#include "../../incl/minishell.h"

void	check_fd_open_error(t_data *data, t_token *token)
{
	char	*file;

	file = token->content;
	if (!file || data->fd->in < 0)
	{
		if (access(file, F_OK < 0))
			exec_error(PATH_ERROR, file);
		else if (access(file, R_OK) < 0)
			exec_error(PERMISSION_ERROR, file);
		data->parse_error = true;
	}
}

void	check_fd_create_error(t_data *data, t_token *token)
{
	char	*file;

	file = token->content;
	if (!file || data->fd->out < 0)
	{
		if (access(file, F_OK) < 0)
			exec_error(PATH_ERROR, file);
		else if (access(file, W_OK) < 0)
			exec_error(PERMISSION_ERROR, file);
		data->parse_error = true;
	}
}

void	check_multiple_pipes(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	if (!tmp)
		return ;
	while (tmp->next != NULL)
	{
		if (tmp->flag == T_PIPE)
		{
			if (tmp->next->flag == T_PIPE)
			{
				print_token_error(PIPE_SYNTAX_ERROR, tmp);
				data->parse_error = true;
				g_exit_code = PIPE_SYNTAX_ERROR;
				return ;
			}
		}
		tmp = tmp->next;
	}
	if (tmp->flag == T_PIPE)
	{
		print_token_error(PIPE_SYNTAX_ERROR, tmp);
		g_exit_code = PIPE_SYNTAX_ERROR;
		data->parse_error = true;
	}
}

bool	check_redir_syntax_error(t_data *data, t_token *token)
{
	if (token->next == NULL || token->next->flag != T_WORD)
	{
		print_token_error(REDIR_SYNTAX_ERROR, token);
		g_exit_code = PIPE_SYNTAX_ERROR;
		data->parse_error = true;
		return (true);
	}
	return (false);
}

bool	check_redir(t_data *data, int flag)
{
	int	i;

	i = 0;
	while (i < NUM_REDIRECTIONS)
	{
		if (flag == data->redir[i])
			return (true);
		i++;
	}
	return (false);
}
