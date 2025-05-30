#include "../../../incl/minishell.h"

void	redirect_from_hdoc(t_data *data)
{
	char	*hdoc;

	hdoc = data->fd->hdoc[data->fd->hdoc_index];
	close_unused_fd_in(data);
	if (data->parse_error == true)
		return ;
	data->fd->in = open(hdoc, O_RDONLY);
	if (access(hdoc, F_OK) < 0)
	{
		exec_error(PATH_ERROR, hdoc);
		data->parse_error = true;
	}
	else if (access(hdoc, R_OK) < 0)
	{
		exec_error(PERMISSION_ERROR, hdoc);
		data->parse_error = true;
	}
}

void	redirect_in(t_data *data, t_token *token)
{
	close_unused_fd_in(data);
	if (data->parse_error == true)
		return ;
	data->fd->in = open(token->content, O_RDONLY);
	check_fd_open_error(data, token);
}

void	redirect_out(t_data *data, t_token *token)
{
	close_unused_fd_out(data);
	data->fd->out = open(token->content, O_CREAT | O_RDWR | O_TRUNC, RIGHTS);
	check_fd_create_error(data, token);
}

void	append(t_data *data, t_token *token)
{
	close_unused_fd_out(data);
	data->fd->out = open(token->content, O_CREAT | O_RDWR | O_APPEND, RIGHTS);
	check_fd_create_error(data, token);
}
