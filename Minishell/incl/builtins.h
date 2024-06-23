#ifndef BUILTINS_H
# define BUILTINS_H

# include "structs.h"
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>

int		check_keys(char **s, int mode);
void	true_env(t_data *data);
char	*make_key(char *s, int *i);
int		export(t_data *data);
int		env(t_data *data);
int		cd(t_data *data);
int		change_pwds(t_data *data);
int		fillempty(t_data *data, char **pwd_path, t_envp **pwd, t_envp **old);
int		home_path(char **s, t_data *data);
int		pwd(void);
int		echo(t_data *data);
int		mini_exit(t_data *data);
int		unset(t_data *data);

#endif
