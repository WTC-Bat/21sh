#include "sh21.h"

//
#include <fcntl.h>
//

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

void redtest()
{
	// Similar to the first.

	// char	*args[2];
	// int		inout[2];
	// pid_t	pid;

	// if (pipe(inout) == -1)
	// {
	// 	ft_putendl_fd("pipe() error", 2);
	// 	exit(0);
	// }
	// args[0] = "ls";
	// args[1] = NULL;
	// pid = fork();
	// if (pid == 0)
	// {
	// 	dup2(inout[1], 1);
	// 	close(inout[0]);
	// 	close(inout[1]);
	// 	execve("/bin/ls", args, 0);
	// 	exit(0);

	// 	// execve("/bin/ls", args, 0);
	// 	// exit(0);
	// }
	// else
	// {
	// 	waitpid(pid, 0 ,0);
	// }

	// This is the closest. I just need to get the output of /bin/ls, not the
	// file its self.

	// int		fd;
	// char	*in;

	// fd = open("/bin/ls", O_RDONLY);
	// in = read_line(fd);
	// ft_putendl(in);
	// close(fd);
	// fd = open("tmp.txt", O_WRONLY);
	// ft_putstr_fd(in, fd);
	// ft_putendl("REDTESTed");

	// We just need to get output, the ft_putendl_fd should be able
	// to write to the file.

	// int		fd;
	// // pid_t	pid;

	// fd = open("tst.txt", 'w');	//open(rhs, 'w');
	// ft_putendl_fd("Test'n'Cheese", fd);
	// close(fd);

	// Don't know about below

	// char	*args[2];
	// // int		fd;
	// pid_t	pid;

	// args[0] = "ls";
	// args[1] = NULL;
	// close(1);
	// open("tst.txt", O_WRONLY);
	// pid = fork();
	// if (pid == 0)
	// {
	// 	execve("/bin/ls", args, 0);
	// 	exit(0);
	// }
	// else
	// {
	// 	waitpid(pid, 0 ,0);
	// }
}
									//split it's self
// static int	redirect(char *lhs, char *rhs, char redir_code)
// {
	
// }

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

// char		*sh21_redirection(char *input, t_env *tenv)
// {
	
// }

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
