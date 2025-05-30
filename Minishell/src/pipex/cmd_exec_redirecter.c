#include "../../incl/minishell.h"

void	exec_bash_cmd(t_data *data)
{
	if (g_exit_code == TERMINATED_BY_CTRL_C)
		exit(TERMINATED_BY_CTRL_C);
	if (data->exec_error == true)
	{
		reset_stdin_stdout(data);
		exec_error(CMD_NOT_FOUND, data->exec->cmd[0]);
		exit(CMD_NOT_FOUND);
	}
	else
	{
		if (execve(data->exec->path, data->exec->cmd, data->env) < 0)
		{
			reset_stdin_stdout(data);
			exec_error(CMD_NOT_FOUND, data->exec->cmd[0]);
			exit(CMD_NOT_FOUND);
		}
	}
	exit(EXIT_SUCCESS);
}

void	exec_transitory_builtin(t_data *data, int builtin)
{
	if (data->fd->in != STDIN_FILENO)
	{
		if (dup2(data->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->in);
	}
	if (data->fd->out != STDOUT_FILENO)
	{
		if (dup2(data->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->out);
	}
	else
		dup2(data->pipe[1], STDOUT_FILENO);
	g_exit_code = data->builtins->funcs[builtin](data);
	dup2(data->pipe[0], STDIN_FILENO);
	close(data->pipe[1]);
	close(data->pipe[0]);
	dup2(data->fd->std_out, STDOUT_FILENO);
}

void	exec_last_builtin(t_data *data, int builtin)
{
	if (data->fd->in != STDIN_FILENO)
	{
		if (dup2(data->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->in);
	}
	if (data->fd->out != STDOUT_FILENO)
	{
		if (dup2(data->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->out);
	}
	g_exit_code = data->builtins->funcs[builtin](data);
}

void	redirect_transitory_cmd(t_data *data)
{
	close(data->pipe[0]);
	if (data->fd->in != STDIN_FILENO)
	{
		if (dup2(data->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->in);
	}
	if (data->fd->out != STDOUT_FILENO)
	{
		if (dup2(data->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->out);
	}
	else
		dup2(data->pipe[1], STDOUT_FILENO);
	close(data->pipe[1]);
}

void	redirect_last_cmd(t_data *data)
{
	if (data->fd->in != STDIN_FILENO)
	{
		if (dup2(data->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->in);
	}
	if (data->fd->out != STDOUT_FILENO)
	{
		if (dup2(data->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit (EXIT_FAILURE);
		}
		close(data->fd->out);
	}
}
