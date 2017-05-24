#include "sh21.h"

/*
**	Redirection Operators:
**	======================
**	<
**	>
**	<<
**	>>
*/

// Don't know about this. It wasn't done with retrieval in mind. It was done
// as 'has_redirection()'

// char	*get_redirect_char(char *input)
// {
// 	int		cnt;
// 	char	r1;
// 	char	r2;
//
// 	cnt = 0;
// 	r1 = '\0';
// 	r2 = '\0';
// 	while (input[cnt] != '\0')
// 	{
// 		if (input[cnt] == '<' || input[cnt] == '>')
// 		{
// 			r1 = input[cnt];
// 			//check for double redirect
// 			if (input[cnt + 1] == input[cnt])
// 			{
// 				r2 = input[cnt + 1];
// 				/*
// 				**	is double, let's move over to that char so that this
// 				**	function doesn't run again and create another redirect
// 				*/
// 				cnt++;
// 			}
// 		}
// 		cnt++;
// 	}
// }

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
	}
	return (0);
}
