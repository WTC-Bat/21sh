NAME = 21sh
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra
SRCS = $(SRC)sh21.c $(SRC)sh21_bltn_echo.c $(SRC)sh21_bltn_env.c \
	   $(SRC)sh21_bltn_setenv.c $(SRC)sh21_bltn_unsetenv.c $(SRC)sh21_funcs.c \
	   $(SRC)sh21_exec.c $(SRC)sh21_bltn_cd.c $(SRC)sh21_cd_navigate.c

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft/libft.a -o 21sh

dbg:
	cd libft && $(MAKE)
	gcc -g -o0 $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft/libft.a -o 21sh

clean:
	rm -f libft/libft.a
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
