#include "../../../incl/minishell.h"

void	close_fds_in_out(t_data *data)
{
	if (data->fd->in != STDIN_FILENO)
		close(data->fd->in);
	if (data->fd->out != STDOUT_FILENO)
		close(data->fd->out);
}

void	close_unused_fd_out(t_data *data)
{
	if (data->fd->out == STDOUT_FILENO)
		return ;
	else if (close(data->fd->out) < 0)
		perror(NULL);
}

void	close_unused_fd_in(t_data *data)
{
	if (data->fd->in == STDIN_FILENO)
		return ;
	else if (close(data->fd->in) < 0)
		perror(NULL);
}
