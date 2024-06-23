#include "../../incl/minishell.h"

static char	**add_cmd_and_path(t_data *data, char **cmd, int words)
{
	int		i;
	t_token	*tmp;
	char	**path;

	path = ft_split(data->tokens->content, SLASH);
	if (!path)
		return (NULL);
	data->exec->path = ft_strdup(data->tokens->content);
	if (!data->exec->path)
		return (NULL);
	cmd[0] = ft_strdup(path[ft_splitlen(path) - 1]);
	if (!cmd[0])
		return (NULL);
	i = 1;
	tmp = data->tokens->next;
	while (i < words)
	{
		cmd[i] = ft_strdup(tmp->content);
		if (!cmd[i])
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	ft_cleansplit(path);
	return (cmd);
}

char	**extract_cmd_from_path(t_data *data)
{
	char	**cmd;
	int		words;

	words = ft_count_word_tokens(data);
	if (words == 0)
		return (NULL);
	cmd = malloc(sizeof(char *) * (words + 1));
	if (!cmd)
		return (NULL);
	cmd[words] = NULL;
	cmd = add_cmd_and_path(data, cmd, words);
	return (cmd);
}
