NAME = minishell

MAIN = ./minishell.c ./minishell_supp_1.c ./minishell_supp_2.c ./minishell_supp_3.c ./minishell_supp_5.c ./minishell_supp_6.c ./minishell_supp_7.c ./minishell_supp_8.c ./minishell_supp_9.c ./minishell_supp_10.c ./minishell_supp_4.c 
OBJ_MAIN = ${MAIN:.c=.o}

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
echo.c minishell_utils.c ft_dir.c env_var.c other_executables.c ft_sep.c \
data_formation.c ft_redir.c exit.c ft_reparse.c ft_cd.c ft_print_prefix.c \
ft_reset_fd.c ft_lst_utils.c ft_error.c ft_checknsettings_sep.c ft_signal.c

PATH_SRCS = ./srcs/

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS = ${_SRCS:.c=.o}

LINK = ar rc

CC = clang

FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

RM = rm -rf

PATH_HEADER = ./minishell_utils.h

.c.o:
		${CC} ${FLAGS} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

PATH_LIBFT = ./srcs/libft/

LIBFT = ./srcs/libft/libft.a

all:        ${NAME}

${NAME}:	${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_LIBFT}
			${CC} ${FLAGS} -ltermcap ${OBJ_MAIN} ${MYLIB} ${LIBFT} -o ${NAME}

clean:
			${RM} ${OBJ_MAIN} ${OBJS}
			make clean -C ${PATH_LIBFT}

fclean:		clean
			${RM} ${NAME} ${MYLIB} ${LIBFT}


re:			fclean all

.PHONY:		all clean fclean re
