#include "sh21.h"

/*
**	Must be careful about some things here. I still need to consider the usage
**	of redirects ('>', '<', etc); and cmd separators (';')
**
**	As is, pipes will only be checked AFTER command splits (';') have been
**	dealt with. So there shouldn't be a problem with command splits (';')
**
**	Functions that are safe from other features:
**	============================================
**	-	is_piped		[Checks if the command is piped]
**	-	pipe_indices	[Gets the indices of all used pipes in command]
**
**	Functions to be wary of:
**	========================
**	-	pipe_commands	[Does not take into consideration other features
**						such as redirects, etc.]
**	-	sh21_pipe		[As above] [Not Yet Implemented]
*/

int		is_piped(char *input)
{
	int		cnt;

	cnt = 0;
	while (input[cnt] != '\0')
	{
		if (input[cnt] == '|')
			if (char_is_in_quote(input[cnt], cnt, input) == 0)
				return (1);
				//check if pipe (|) is surrounded by spaces?
		cnt++;
	}
	return (0);
}

//Could probably use this to test
int		*pipe_indices(char *input)
{
	int		*indices;
	int		cnt;
	int		idx;

	indices = NULL;
	cnt = 0;
	idx = 0;
	while (input[cnt] != '\0')
	{
		if (input[cnt] == '|')
		{
			if (char_is_in_quote(input[cnt], cnt, input) == 0)
			{
				indices[idx] = cnt;
				idx++;
			}
		}
		cnt++;
	}
	pipe_indices[idx] = -1;
	return (indices);
}

char	**pipe_commands(char *input, int *pipe_indices)
{
	// int		cnt;
	int		start;
	int		end;

	if (pipe_indices == NULL)
		return (NULL);
	start = -1;
	end = -1;
	while (pipe_indices[cnt] != -1)
	{

	}


	// cnt = 0;
	// while (input[cnt] != '\0')
	// {
	//
	// }
}

void	sh21_pipe(char *input)
{

}
