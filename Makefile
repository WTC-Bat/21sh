NAME = 21sh
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra
SRCS = $(SRC)sh21.c $(SRC)sh21_bltn_echo.c $(SRC)sh21_bltn_env.c \
	   $(SRC)sh21_bltn_setenv.c $(SRC)sh21_bltn_unsetenv.c $(SRC)sh21_funcs.c \
	   $(SRC)sh21_exec.c $(SRC)sh21_bltn_cd.c $(SRC)sh21_cd_navigate.c \
	   $(SRC)sh21_cmd_split.c $(SRC)sh21_handle_input.c $(SRC)sh21_sort_quote.c \
	   $(SRC)sh21_cmd_split_funcs.c $(SRC)sh21_semicolon_funcs.c \
	   $(SRC)sh21_sort_quote_funcs.c $(SRC)sh21_tquot_funcs.c \
	   $(SRC)sh21_set_start_end.c

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft/libft.a -o $(NAME)

dbg:
	cd libft && $(MAKE)
	gcc -g -o0 $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft/libft.a -o $(NAME)

clean:
	rm -f libft/libft.a
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
