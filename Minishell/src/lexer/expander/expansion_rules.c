#include "../../../incl/minishell.h"

void	expand_last_return(t_data *data, t_lex *lex)
{
	char	*exit_code;
	bool	is_sep;

	exit_code = ft_itoa(g_exit_code);
	lex->buf = ft_strjoin(lex->buf, exit_code);
	free(exit_code);
	exit_code = NULL;
	lex->i++;
	lex->c = data->input[lex->i];
	is_sep = check_sep(data, lex->c);
	while (is_sep == false && lex->c != '\0')
	{
		is_sep = check_sep(data, lex->c);
		if (is_sep == true)
			break ;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
		lex->c = data->input[lex->i];
	}
}

void	handle_multiple_dollars(t_data *data, t_lex *lex)
{
	bool	is_sep;

	while (lex->c == DOLLAR)
	{
		lex->buf = ft_join_char(lex->buf, DOLLAR);
		lex->i++;
		lex->c = data->input[lex->i];
	}
	is_sep = check_sep(data, lex->c);
	if (is_sep == true && lex->c != DOUBLE_QUOTE && lex->c != SINGLE_QUOTE)
	{
		lex->expansion = false;
		if (lex->double_quote_mode == false)
			add_token(data, lex);
	}
	else
	{
		if (lex->double_quote_mode == false)
			add_token(data, lex);
		lex->expansion = false;
	}
}

void	handle_one_dollar(t_data *data, t_lex *lex)
{
	bool	is_sep;

	lex->buf = ft_join_char(lex->buf, DOLLAR);
	is_sep = check_sep(data, lex->c);
	if (is_sep == true && lex->c != DOUBLE_QUOTE && lex->c != SINGLE_QUOTE)
	{
		lex->expansion = false;
		if (lex->double_quote_mode == false)
			add_token(data, lex);
	}
	else
	{
		if (lex->double_quote_mode == false)
			add_token(data, lex);
		lex->expansion = false;
	}
	lex->i++;
}
