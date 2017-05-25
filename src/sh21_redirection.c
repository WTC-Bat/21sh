#include "sh21.h"

/*
**	Redirection Operators:
**	======================
**	<	-	l
**	>	-	r
**	<<	-	L
**	>>	-	R

**	Both 'lhs' and 'rhs' need to be trimmed prior to being passed to
**	'sh21_redirect()'
*/
// void	sh21_redirection(char *redir_str)	//this version would need to do the
										//split it's self
static int	redirect(char *lhs, char *rhs, char redir_code)
{
	int		inout[2];

	if (pipe(inout) == 0)
	{
		
	}
	else
	{
		ft_putendl_fd("Error creating pipe [sh21_redirect()]", 2);
	}
}

// static int	get_redir_indices(char *input)
// {
// 	int		idx;
// 	int		iidx;
// 	int		*indices;

// 	idx = 0;
// 	iidx = 0;
// 	indices = NULL;
// 	while (input[idx] != '\0')
// 	{
// 		if (input[idx] == '<' || input[idx] == '>')
// 		{
// 			if (input[idx + 1] != input[idx])
// 			{
// 				indices[iidx] = idx;
// 				iidx++;
// 			}
// 		}
// 		idx++;
// 	}
// }

char		*sh21_redirection(char *input, t_env *tenv)
{
	
}

// int		has_redirection(char **args)
// {
// 	int		idx;
// 	int		cidx;

// 	idx = 0;
// 	cidx = 0;
// 	while (args[idx] != NULL)
// 	{
// 		while (args[idx][cidx] != '\0')
// 		{

// 		}
// 		idx++;
// 	}
// }

/*
**	This version is for taking a single char *.
*/
int		has_redirection(char *input)
{
	int		cnt;

	cnt = 0;
	while (input[cnt] != '\0')
	{
		if (input[cnt] == '<' || input[cnt] == '>')
			if (char_is_in_quote(input[cnt], cnt, input) == 0)
				return (1);
				// Check if redirection surrounded by spaces?
		cnt++;
	}
	return (0);
}
