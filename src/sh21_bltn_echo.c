#include "sh21.h"

static void	print_val(t_env *tenv, char *arg)
{
	int		sublen;
	char	*varname;
	char	*env_val;

	sublen = ft_strlen(arg) - 1;
	varname = ft_strsub(arg, 1, sublen);
	env_val = get_env_val(tenv, varname);
	if (env_val != NULL)
	{
		ft_putstr(env_val);
		ft_putchar(' ');
		free(env_val);
		env_val = NULL;
	}
	free(varname);
	varname = NULL;
}

void		msh_echo(t_env *tenv, char **eargv)
{
	int		cnt;

	cnt = 1;
	while (eargv[cnt] != NULL)
	{
		if (eargv[cnt][0] == '$')
		{
			print_val(tenv, eargv[cnt]);
		}
		else
		{
			ft_putstr(eargv[cnt]);
			ft_putchar(' ');
		}
		cnt++;
	}
	ft_putchar('\n');
}