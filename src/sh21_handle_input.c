/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21_handle_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 07:37:20 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/11 07:37:21 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	has_double_scolon(char *input)
{
	int		cnt;

	cnt = 0;
	while (input[cnt] != '\0')
	{
		if (input[cnt] == ';' && char_is_in_quote(input[cnt], cnt, input) == 0)
		{
			if (input[cnt + 1] != '\0' && input[cnt + 1] == ';')
			{
				if (char_is_in_quote(input[cnt + 1], cnt + 1, input) == 0)
				{
					ft_putendl_fd("Unexpected character ';;'", 2);
					return (1);
				}
			}
		}
		cnt++;
	}
	return (0);
}

static int	run_input(char **args, t_env *tenv)
{
	if ((ft_strequ(args[0], "env")) == 1)
		print_env(tenv);
	else if ((ft_strequ(args[0], "echo")) == 1)
		msh_echo(tenv, args);
	else if ((ft_strequ(args[0], "setenv")) == 1)
		msh_setenv(&tenv, args);
	else if ((ft_strequ(args[0], "unsetenv")) == 1)
		msh_unsetenv(&tenv, args);
	else if (ft_strequ(args[0], "cd") == 1)
		msh_cd(args, tenv);
	else if ((ft_strequ(args[0], "exit")) == 1)
		return (1);
	else
	{
		if (msh_exec(args, tenv) == -1)
		{
			ft_putstr(args[0]);
			ft_putendl(": Unknown command");
		}
	}
	return (0);
}

static int	handle_multi_command(char *input, t_env *tenv)
{
	t_list	*cmds;
	t_list	*root;
	char	**args;
	int		done;

	cmds = msh_cmd_split(input);
	done = 0;
	root = cmds;
	while (cmds != NULL)
	{
		//check redpip?
		args = msh_sort_quote((char *)cmds->content);
		done = run_input(args, tenv);
		ft_starfree(args);
		cmds = cmds->next;
		if (done == 1)
			return (1);
	}
	cmds_free(root);
	return (done);
}

int			check_input(char *input)
{
	if (input[0] != '\0' && input[0] != ' ' && input[0] != '\t')
	{
		if (has_double_scolon(input) == 0)
			return (1);
		else
			ft_strdel(&input);
	}
	return (0);
}

int			msh_handle_input(char *input, t_env *tenv)
{
	char	**args;
	int		done;

	args = NULL;
	done = 0;
	if (has_cmd_splitter(input) == 1)
	{
		if (only_colon(input) == 0)
			done = handle_multi_command(input, tenv);
	}
	else
	{
		//Check redpip?
		//
		// if (has_redirection(input) == 1)
		// 	ft_putendl("HAS REDIRECTION!");
		// else
		// 	ft_putendl("DOES NOT HAVE REDIRECTION!");
		//
		args = msh_sort_quote(input);
		done = run_input(args, tenv);
		ft_starfree(args);
	}
	return (done);
}
