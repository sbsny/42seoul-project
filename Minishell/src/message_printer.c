#include "../incl/minishell.h"

void	print_error(int error)
{
	if (error == SINGLE_QUOTE_MISSING)
		printf("minishell:	syntax error. Missing '\n");
	else if (error == DOUBLE_QUOTE_MISSING)
		printf("minishell:	syntax error. Missing \"\n");
	else if (error == EXIT_ERROR)
		printf("minishell: exit: too many arguments\n");
	else if (error == INVALID_PATH)
		printf("minishell: Invalid file or directory:");
	else if (error == OLDPWD_ERROR)
		printf("minishell: cd: OLDPWD not set\n");
	else if (error == ENV_ERROR)
		printf("minishell: env: too many arguments\n");
}

void	print_token_error(int error, t_token *token)
{
	char	*redir;

	if (token->next == NULL)
		redir = ft_strdup("newline");
	else
		redir = ft_strdup(token->next->content);
	if (error == PIPE_SYNTAX_ERROR)
		printf("minishell: syntax error near unexpected token `||'\n");
	else if (error == REDIR_SYNTAX_ERROR)
		printf("minishell: syntax error near unexpected token `%s'\n", redir);
	free(redir);
	redir = NULL;
}

int	exec_error(int error, char *s)
{
	if (error == EXPORT_ERROR)
		printf("minishell: export: `%s': not a valid identifier\n", s);
	else if (error == EXIT_ARG_ERROR)
		printf("minishell: exit: %s: numeric argument required\n", s);
	else if (error == CMD_ERROR)
		printf("minishell: command: %s: not found\n", s);
	else if (error == CMD_NOT_FOUND)
		printf("minishell: %s: command not found\n", s);
	else if (error == PATH_ERROR)
		printf("minishell: %s: No such file or directory\n", s);
	else if (error == UNSET_ERROR)
		printf("minishell: unset: `%s': not a valid identifier\n", s);
	else if (error == PERMISSION_ERROR)
		printf("minishell: %s: Permission denied\n", s);
	else if (error == EMPTY_KEY_ERROR)
		printf("minishell: cd: %s not set\n", s);
	return (1);
}
