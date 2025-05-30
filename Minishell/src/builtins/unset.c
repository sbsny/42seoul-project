#include "../../incl/minishell.h"

void	ft_dl_node(t_data **data, t_envp *node)
{
	t_envp	*tmp;

	tmp = (*data)->envp;
	if (ft_strcmp(tmp->key, node->key) == 0)
	{
		(*data)->envp = tmp->next;
		free(node->val);
		free(node->key);
		free(node);
		return ;
	}
	while (tmp->next)
	{
		if ((ft_strcmp(tmp->next->key, node->key) == 0))
		{
			tmp->next = tmp->next->next;
			free(node->key);
			free(node->val);
			free(node);
			break ;
		}
		tmp = tmp->next;
	}
}

static int	check_keys_help(char **s, int *i, int *j, int mode)
{
	while (s[(*i)] != NULL && s[(*i)][(*j)] && s[(*i)][(*j) + 1])
	{
		(*j)++;
		if (s[*i][*j] == '=' || (s[*i][*j] == '+' \
		&& *j < (int)ft_strlen(s[*i]) && s[*i][(*j) + 1] == '='))
			break ;
		if (!ft_isalpha(s[*i][*j]) && !ft_isdigit((int)s[*i][*j]) \
		&& s[*i][*j] != '_')
		{
			exec_error(mode, s[*i]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_keys(char **s, int mode)
{
	int	i;
	int	j;
	int	len;
	int	ret;

	len = ft_splitlen(s);
	j = 0;
	i = 1;
	ret = 0;
	while (s[i] && i < len)
	{
		j = 0;
		if (!ft_isalpha(s[i][j]) && s[i][j] != '_')
			ret += exec_error(mode, s[i]);
		else
			ret += check_keys_help(s, &i, &j, mode);
		i++;
	}
	return (ret);
}

static int	check_unset(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	if (!ft_isalpha(s[0]) && s[0] != '_')
		return (1);
	while (s[i])
	{
		if (!ft_isalpha(s[i]) && !ft_isdigit(s[i]) && s[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	unset(t_data *data)
{
	t_envp	*tmp;
	int		i;
	int		errors;

	errors = 0;
	i = 1;
	if (!data->exec->cmd[1])
		return (EXIT_SUCCESS);
	while (data->exec->cmd[i])
	{
		tmp = NULL;
		if (check_unset(data->exec->cmd[i]) == EXIT_FAILURE)
		{
			errors++;
			exec_error(UNSET_ERROR, data->exec->cmd[i]);
		}
		else
			tmp = ft_getenvp(data, data->exec->cmd[i]);
		if (tmp != NULL)
			ft_dl_node(&data, tmp);
		i++;
	}
	if (errors > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
