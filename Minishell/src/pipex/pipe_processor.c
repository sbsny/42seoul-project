#include "../../incl/minishell.h"

void	catch_exit_code(t_data *data)
{
	int	status;

	status = 0;
	waitpid(data->pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
}

static int	create_fork(t_data *data)
{
	signal(SIGINT, SIG_IGN);
	data->pid = fork();
	if (data->pid < 0)
	{
		perror(NULL);
		free_cmd_and_path(data);
		return (-1);
	}
	return (0);
}

static int	create_pipe(t_data *data)
{
	if (pipe(data->pipe) < 0)
	{
		perror(NULL);
		free_cmd_and_path(data);
		return (-1);
	}
	return (0);
}

void	pipe_transitory_cmd(t_data *data)
{
	int	builtin;

	if (create_pipe(data) < 0)
		return ;
	if (data->exec->no_cmd == true || data->parse_error == true)
	{
		redirect_stdin_to_pipe(data);
		return ;
	}
	builtin = ft_get_builtin(data);
	if (builtin >= 0)
		exec_transitory_builtin(data, builtin);
	else
	{
		if (create_fork(data) < 0)
			return ;
		sleep(10);
		if (data->pid == 0)
		{
			ft_signals(CHILD_PROCESS);
			redirect_transitory_cmd(data);
			exec_bash_cmd(data);
		}
		redirect_stdin_to_pipe(data);
	}
}

void	pipe_last_cmd(t_data *data)
{
	int	builtin;

	if (data->exec->no_cmd == true || data->parse_error == true)
	{
		reset_stdin_stdout(data);
		if (data->parse_error == true)
			g_exit_code = EXIT_FAILURE;
		return ;
	}
	builtin = ft_get_builtin(data);
	if (builtin >= 0)
		exec_last_builtin(data, builtin);
	else
	{
		if (create_fork(data) < 0)
			return ;
		if (data->pid == 0)
		{
			ft_signals(CHILD_PROCESS);
			redirect_last_cmd(data);
			exec_bash_cmd(data);
		}
	}
	reset_stdin_stdout(data);
}
