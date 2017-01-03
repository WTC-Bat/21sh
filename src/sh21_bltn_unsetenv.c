/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21_bltn_unsetenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:16:48 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/03 14:16:49 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		unsetenv_args_valid(t_env *tenv, char **args)
{
	char	*envval;

	if ((ft_strequ(args[0], "unsetenv")) == 0)
	{
		ft_putendl("Error: Unexpected error!");
		return (0);
	}
	if (strcnt(args) < 2)
	{
		ft_putendl("Error: Too few arguments for \"unsetenv\"");
		return (0);
	}
	if (strcnt(args) > 2)
	{
		ft_putendl("Error: Too many arguments for \"unsetenv\"");
		return (0);
	}
	if ((envval = get_env_val(tenv, args[1])) == NULL)
	{
		ft_putendl("Error: Variable not found");
		return (0);
	}
	else
		ft_strdel(&envval);
	return (1);
}

t_env	*remove_var(t_env *tenv, char *varname)
{
	t_env	*tmp;

	if (tenv == NULL)
		return (NULL);
	if ((ft_strequ(tenv->var, varname)) == 1)
	{
		tmp = tenv->next;
		ft_strdel(&(tenv)->var);
		ft_strdel(&(tenv)->val);
		free(tenv);
		return (tmp);
	}
	tenv->next = remove_var(tenv->next, varname);
	return (tenv);
}

void	sh21_unsetenv(t_env **tenv, char **args)
{
	if (unsetenv_args_valid(*tenv, args) == 1)
		*tenv = remove_var(*tenv, args[1]);
}
