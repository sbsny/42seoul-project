#include "../../incl/minishell.h"

char	*ft_join_char(char *buf, char c)
{
	int		i;
	char	*join;

	join = malloc(sizeof(char) * (ft_strlen(buf) + 2));
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
	}
	join[i] = c;
	i++;
	join[i] = '\0';
	free(buf);
	buf = NULL;
	return (join);
}
