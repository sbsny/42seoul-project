#include "../../incl/minishell.h"

void	init_fd(t_data *data)
{
	data->fd->hdoc = NULL;
	data->fd->in = STDIN_FILENO;
	data->fd->out = STDOUT_FILENO;
	data->fd->hdoc_index = 0;
}

void	dup_stdin_and_stdout(t_data *data)
{
	data->fd->std_in = dup(STDIN_FILENO);
	if (!data->fd->std_in)
	{
		free(data->fd);
		exit(EXIT_FAILURE);
	}
	data->fd->std_out = dup(STDOUT_FILENO);
	if (!data->fd->std_out)
	{
		free(data->fd);
		exit(EXIT_FAILURE);
	}
}
