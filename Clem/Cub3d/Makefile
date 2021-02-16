NAME = cub3D.out

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

BUFFER = -D BUFFER_SIZE=1

RM = rm -rf

PATH_HEADER = ./

.c.o:
			${CC} ${FLAGS} ${BUFFER} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

PATH_MLX = ./libx/

MLX = ./libx/libmlx.a

all:		${NAME}

${NAME}:	${MV} ${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX}
			make -C ./libx/minilibx/
			mv ./libx/minilibx/libmlx.dylib ./
			${CC} ${FLAGS} ${OBJ_MAIN} ${MYLIB} ${MLX} libmlx.dylib -framework OpenGL -framework AppKit -o ${NAME}

clean:
			${RM} ${OBJ_MAIN} ${OBJS}
			make clean -C ${PATH_MLX}

fclean:		clean
			${RM} ${NAME} ${MLX} libmlx.dylib ${MYLIB}
			make clean -C ${PATH_MLX}
			make clean -C ./libx/minilibx/

re:			fclean all

.PHONY:		all clean fclean re
