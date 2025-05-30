#include "../../incl/minishell.h"

static char	*join_tmp_to_buf(char *buf, char *tmp)
{
	int		i;
	int		j;
	char	*join;

	join = malloc(sizeof(char) * ((ft_strlen(buf) + ft_strlen(tmp)) + 1));
	if (!join)
	{
		free(tmp);
		return (NULL);
	}
	i = 0;
	while (buf[i] != '\0')
	{
		join[i] = buf[i];
		i++;
	}
	j = 0;
	while (tmp[j] != '\0')
		join[i++] = tmp[j++];
	join[i] = '\0';
	free(tmp);
	return (join);
}

char	*ft_join_tilde(char *buf, char *tmp, int flag)
{
	char	*join;

	if (flag == 1)
	{
		join = ft_strdup(buf);
		free(tmp);
		return (join);
	}
	else
		join = join_tmp_to_buf(buf, tmp);
	return (join);
}
