#ifndef SH21_H
# define SH21_H

# define COL_HGRN_BLD "\x1b[92;1m"
# define COL_DEF "\x1b[0m"
# define TRM_CLR "\e[1;1H\e[2J"

# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct		s_env
{
	char			*var;
	char			*val;
	struct s_env	*next;
}					t_env;

int					cd_args_valid(char *arg);
int					cd_navigate(char *arg, t_env *tenv);
int					cd_navigate_basic(t_env *tenv, char *arg);
int					cd_navigate_origin_home(t_env *tenv, char *arg);
void				clear_star(char **args);
void				free_star(char **star);
void				free_tenv(t_env *tenv);
t_env				*get_env();
char				*get_env_val(t_env *tenv, char *varname);
void				sh21_cd(char **args, t_env *tenv);
void				sh21_echo(t_env *tenv, char **eargv);
int					sh21_exec(char **args, t_env *tenv);
void				sh21_setenv(t_env **tenv, char **args);
void				sh21_unsetenv(t_env **tenv, char **args);
void				print_env(t_env *tenv);
char				*read_line(const int fd);
void				replace_var(t_env *tenv, char *var, char *val);
int					strcnt(char **args);
int					tenv_count(t_env *tenv);
t_env				*t_env_reverse(t_env *tenv);
char				**tenv_to_star(t_env *tenv);
char				*cd_get_back_path(t_env *tenv, char *arg);

#endif
