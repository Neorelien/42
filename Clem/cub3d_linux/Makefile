NAME = cub3D

MAIN = ./cub3d.c

OBJ_MAIN = ${MAIN:.c=.o}

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
cub3d_utils.c textures.c error.c save.c\
colors.c ft_is_spec.c map_parsing.c display.c\
cub3d_utils2.c exit.c create_map.c window.c map_check.c sprite.c ft_is_spec.c \
ft_mlx.c raycasting.c move_hero.c display_sprite.c ft_key.c texture_data.c
PATH_SRCS = ./

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS = ${_SRCS:.c=.o}

LINK = ar rc

CC = clang

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

PATH_HEADER = ./

.c.o:
			${CC} ${FLAGS} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

PATH_MLX_LINUX = ./minilibx-linux/

MLX_LINUX = ./minilibx-linux/libmlx_Linux.a

all:		${NAME}

${NAME}:	${MV} ${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX_LINUX}
			${CC} ${FLAGS} -o3 ${OBJ_MAIN} ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o ${NAME}

clean:
			${RM} ${OBJ_MAIN} ${OBJS}
			make clean -C ${PATH_MLX_LINUX}

fclean:		clean
			${RM} ${NAME} ${MYLIB} ${MLX_LINUX}
			

re:			fclean all

.PHONY:		all clean fclean re
