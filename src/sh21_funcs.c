/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:09:31 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/02 14:02:11 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		only_colon(char *input)
{
	int		cnt;

	cnt = 0;
	while (input[cnt] != '\0')
	{
		if (ft_iswhitespace(input[cnt]) == 0 && input[cnt] != ';')
			return (0);
		cnt++;
	}
	return (1);
}

int		strcnt(char **args)
{
	int		cnt;

	cnt = 0;
	while (args[cnt] != NULL)
		cnt++;
	return (cnt);
}

char	*read_line(const int fd)
{
	char	*rline;
	char	*line;

	rline = (char *)malloc(sizeof(char) * 1024);
	ft_memset(rline, '\0', 1024);
	read(fd, rline, 1024);
	line = ft_strtrim(rline);
	if (line[0] == ';')
	{
		ft_putendl_fd("Unexpected character: ';'", 2);
		ft_strdel(&rline);
		ft_strdel(&line);
		return (NULL);
	}
	ft_strdel(&rline);
	return (line);
}

void	free_tenv(t_env *tenv)
{
	t_env	*tmp;

	while (tenv != NULL)
	{
		tmp = tenv;
		tenv = tenv->next;
		ft_strclr(tmp->var);
		free(tmp->var);
		tmp->var = NULL;
		ft_strclr(tmp->val);
		free(tmp->val);
		tmp->val = NULL;
		free(tmp);
		tmp = NULL;
	}
	tenv = NULL;
}

void	free_star(char **star)
{
	int		cnt;

	cnt = 0;
	while (star[cnt] != NULL)
	{
		ft_strclr(star[cnt]);
		free(star[cnt]);
		star[cnt] = NULL;
		cnt++;
	}
	free(star);
	star = NULL;
}
