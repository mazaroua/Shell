NAME = minishell
CC = cc 
FLAGS = -w -Wall -Werror -Wextra 
SRC = minishell.c utils.c remove_spaces.c tokenizer.c tokenizer_utils.c tokenizer_utils2.c syntax.c parser.c parser_utils.c expander.c \
		execution.c execution_2.c execution_utils.c cdpwd.c redirections.c redirections_2.c ft_heredoc.c execution_main_utils.c \
		init_env.c export.c unset.c echo.c exit.c export_utils1.c  export_utils2.c export_utils3.c export_utils4.c init_env_utils.c \
		utils3.c utils4.c utils5.c ft_split.c 
OBJ = $(SRC:.c=.o)


all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lreadline

%.o:%.c minishell.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all fclean clean   
