#include "../../incl/minishell.h"

void	free_cmd_and_path(t_data *data)
{
	ft_cleansplit(data->exec->cmd);
	data->exec->cmd = NULL;
	free(data->exec->path);
	data->exec->path = NULL;
}

static void	extract_cmd_and_path(t_data *data, t_token *token)
{
	if (data->exec->no_cmd == true || !data->tokens->content)
		return ;
	if (token->content[0] == '.' || token->content[0] == SLASH)
	{
		data->exec->cmd = extract_cmd_from_path(data);
		if (!data->exec->cmd || !data->exec->path)
		{
			data->exec_error = true;
			return ;
		}
	}
	else
	{
		data->exec->cmd = get_cmd(data);
		if (data->exec_error == true)
			return ;
		data->exec->path = get_cmd_path(data);
		if (!data->exec->path)
			data->exec_error = true;
	}
}

static void	exec_cmd(t_data *data, t_token *token)
{
	extract_cmd_and_path(data, token);
	if (data->exec->cmd_num < data->exec->last_cmd)
		pipe_transitory_cmd(data);
	else if (data->exec->cmd_num == data->exec->last_cmd)
		pipe_last_cmd(data);
	free_cmd_and_path(data);
}

static void	reset_params(t_data *data)
{
	data->parse_error = false;
	data->exec_error = false;
	data->exec->no_cmd = false;
	data->fd->in = STDIN_FILENO;
	data->fd->out = STDOUT_FILENO;
}

void	execute_tokens(t_data *data)
{
	init_exec(data);
	data->exec->last_cmd = ft_get_num_cmds(data);
	data->fd->hdoc_index = 0;
	while (data->tokens != NULL)
	{
		reset_params(data);
		resolve_redirections(data);
		if (!data->tokens)
		{
			reset_stdin_stdout(data);
			set_global_exit_code(data);
		}
		else if (data->exec->no_cmd == true || data->tokens->flag == T_WORD)
		{
			exec_cmd(data, data->tokens);
			data->exec->cmd_num++;
		}
		delete_words(data);
		ft_del_first_token(&data);
		close_fds_in_out(data);
	}
	catch_exit_code(data);
	destroy_hdocs(data);
}
