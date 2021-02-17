NAME = cub3D

MAIN = ./cub3d.c

OBJ_MAIN = ${MAIN:.c=.o}

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
save.c save2.c frame.c move_hero.c clear_image.c ft_sprite.c cub3d_utils.c \
map_check.c textures.c free.c error.c create_map.c get_hero.c game_settings.c \
press_key.c texture_angle.c ft_is_spec.c display_sprite.c colors.c ray.c \
move_hero2.c get_info.c cub3d_utils2.c

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
