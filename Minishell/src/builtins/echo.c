#include "../../incl/minishell.h"

static bool	is_flag(t_token *token)
{
	int	i;

	i = 0;
	if (token->content[i] == '-')
	{
		i++;
		while (token->content[i] != '\0')
		{
			if (token->content[i] != 'n')
				return (false);
			i++;
		}
		if (token->content[0] == '-' && ft_strlen(token->content) == 1)
			return (false);
		else
			return (true);
	}
	return (false);
}

void	print_args(t_data *data, int words)
{
	int		i;
	int		flag;
	bool	check_flag;
	t_token	*tmp;

	i = 1;
	flag = 0;
	check_flag = false;
	tmp = data->tokens->next;
	while (i < words)
	{
		if (is_flag(tmp) == true && check_flag != true)
			flag = 1;
		else
		{
			printf("%s", tmp->content);
			if (i < words - 1)
				printf(" ");
			check_flag = true;
		}
		i++;
		tmp = tmp->next;
	}
	if (flag == 0)
		printf("\n");
}

int	echo(t_data *data)
{
	int	words;

	words = ft_count_word_tokens(data);
	if (words == 1)
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	print_args(data, words);
	g_exit_code = EXIT_SUCCESS;
	return (g_exit_code);
}
