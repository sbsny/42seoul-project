#include "../../incl/minishell.h"

char	*ft_strjoin(char *buf, char *tmp)
{
	int		i;
	int		j;
	char	*join;

	if (!tmp)
		return (buf);
	join = malloc(sizeof(char) * ((ft_strlen(buf) + ft_strlen(tmp)) + 1));
	if (!join)
		return (NULL);
	i = 0;
	if (buf != NULL)
	{
		while (buf[i] != '\0')
		{
			join[i] = buf[i];
			i++;
		}
		free(buf);
		buf = NULL;
	}
	j = 0;
	while (tmp[j] != '\0')
		join[i++] = tmp[j++];
	join[i] = '\0';
	return (join);
}
