#include "../../incl/minishell.h"

static void	lex_pipe(t_lex *lex)
{
	if (lex->c == '|')
	{
		lex->flag = T_PIPE;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
	}
}

static void	lex_redirect_out(t_data *data, t_lex *lex)
{
	if (lex->c == '>')
	{
		lex->flag = T_REDIRECT_OUT;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
		lex->c = data->input[lex->i];
		if (lex->c == '>')
		{
			lex->flag = T_APPEND;
			lex->buf = ft_join_char(lex->buf, lex->c);
			lex->i++;
		}
	}
}

static void	lex_redirect_in(t_data *data, t_lex *lex)
{
	if (lex->c == '<')
	{
		lex->flag = T_REDIRECT_IN;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
		lex->c = data->input[lex->i];
		if (lex->c == '<')
		{
			lex->flag = T_HEREDOC;
			lex->buf = ft_join_char(lex->buf, lex->c);
			lex->i++;
		}
	}
}

void	handle_redirections(t_data *data, t_lex *lex)
{
	if (lex->c == '<')
		lex_redirect_in(data, lex);
	else if (lex->c == '>')
		lex_redirect_out(data, lex);
	else
		lex_pipe(lex);
	add_token(data, lex);
}

bool	find_redirections(t_lex *lex)
{
	if (lex->c == '<' || lex->c == '>' || lex->c == '|')
		return (true);
	return (false);
}
