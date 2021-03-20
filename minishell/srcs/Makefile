NAME = minishell

MAIN = ./test.c

OBJ_MAIN = ${MAIN:.c=.o}

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
test.c

PATH_SRCS = ./

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS = ${_SRCS:.c=.o}

LINK = ar rc

CC = clang

FLAGS = -ltermcap

RM = rm -rf

PATH_HEADER = ./

.c.o:
		${CC} ${FLAGS} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

PATH_LIBFT = ./libft/

LIBFT = ./libft/libft.a

all:        ${NAME}

${NAME}:	${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_LIBFT}
			${CC} ${FLAGS} -fsanitize=address ${OBJ_MAIN} ${MYLIB} ${LIBFT} -o ${NAME}

clean:
			${RM} ${OBJ_MAIN} ${OBJS}
			make clean -C ${PATH_LIBFT}

fclean:		clean
			${RM} ${NAME} ${MYLIB} ${LIBFT}


re:			fclean all

.PHONY:		all clean fclean re
