/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 10:31:55 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/05/22 10:34:22 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	put_prompt(t_env *tenv)
{
	char	*prompt;
	char	*user;
	char	*tmp;

	user = get_env_val(tenv, "USER");
	if (user == NULL)
		user = ft_strdup("minishell");
	tmp = ft_strdup(COL_HGRN_BLD);
	prompt = ft_strjoin(tmp, user);
	ft_strdel(&tmp);
	tmp = ft_strdup(prompt);
	ft_strdel(&prompt);
	prompt = ft_strjoin(tmp, "@WTC $> ");
	ft_strdel(&tmp);
	tmp = ft_strdup(prompt);
	ft_strdel(&prompt);
	prompt = ft_strjoin(tmp, COL_DEF);
	ft_putstr(prompt);
	ft_strdel(&prompt);
	ft_strdel(&tmp);
	ft_strdel(&user);
}

static int	has_arg(char **argv, char c)
{
	int		scnt;
	int		cnt;

	scnt = 0;
	cnt = 0;
	while (argv[scnt] != NULL)
	{
		if (argv[scnt][0] == '-')
			while (argv[scnt][cnt] != '\0')
			{
				if (argv[scnt][cnt] == c)
					return (1);
				cnt++;
			}
		cnt = 0;
		scnt++;
	}
	return (0);
}

static int	loop(t_env *tenv)
{
	char	*input;
	int		done;

	done = 0;
	put_prompt(tenv);
	input = read_line(0);
	if (input == NULL)
		return (0);
	if (check_input(input) == 1)
	{
		done = msh_handle_input(input, tenv);
		ft_strdel(&input);
	}
	return (done);
}

int			main(int argc, char **argv)
{
	int			done;
	t_env		*tenv;
	extern char	**environ;

	if (argc < 1)
	{
		ft_putendl("How did you get this far?");
		return (1);
	}
	done = 0;
	tenv = get_env(environ);
	if (has_arg(argv, 'c') == 1)
		ft_putstr(TRM_CLR);
	while (done == 0)
		done = loop(tenv);
	free_tenv(tenv);
	return (0);
}
