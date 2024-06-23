#include "../../incl/minishell.h"

void	reset_stdin_stdout(t_data *data)
{
	dup2(data->fd->std_in, STDIN_FILENO);
	dup2(data->fd->std_out, STDOUT_FILENO);
}

void	set_global_exit_code(t_data *data)
{
	if (data->parse_error == true)
		g_exit_code = EXIT_FAILURE;
	else if (g_exit_code != TERMINATED_BY_CTRL_C)
		g_exit_code = EXIT_SUCCESS;
}
