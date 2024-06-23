#include "../../incl/minishell.h"

static void	ctrl_c(int sig_num)
{
	struct termios	att;

	(void)sig_num;
	tcgetattr(STDIN_FILENO, &att);
	att.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &att);
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

static void	c_ctrlc(int sig)
{
	(void)sig;
	signal(SIGINT, SIG_DFL);
	ioctl(STDOUT_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
}

static int	handle_hered(int sig_num)
{
	static int	save;

	if (sig_num == 10)
		return (save);
	if (sig_num == 2)
	{
		save = 11;
		return (1);
	}
	save = 0;
	return (-1);
}

void	ft_signals(int flag)
{
	if (flag == MAIN_PROCESS)
	{
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (flag == CHILD_PROCESS)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, &c_ctrlc);
	}
	else if (flag == HDOC)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &ctrl_c);
		signal(SIGINT, (void *)handle_hered);
		if (handle_hered(10) == 11)
			exit(TERMINATED_BY_CTRL_C);
	}
}
