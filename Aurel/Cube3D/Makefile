# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 12:00:36 by awery             #+#    #+#              #
#    Updated: 2021/02/14 19:53:40 by Aurelien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cube3D

all: $(NAME)

$(NAME):
	cd dyna_minilibx ; make clean ; make ; cp libmlx.dylib ../ ; cd .. ;cd src/Libft ; make ; cd ../../ ; clang -Wall -Werror -Wextra -D BUFFER_SIZE=20 -fsanitize=address -g3 exit.c to_bmp_2.c texture_init.c texture_2.c td_2.c sprite_2.c player_move_2.c map_checker_2.c element_3.c element_2.c display_2.c direction_support.c direction_2.c raycasting_2.c raycasting_1.c pos.c arg_checker.c closing.c sprite.c to_bmp.c td.c cubetd.c texture.c direction.c map_checker.c display.c elements.c player_move.c minilibx/libmlx.a libmlx.dylib -framework OpenGL -framework AppKit src/get_next_line.c src/get_next_line_utils.c src/Libft/libft.a -o cube3D

fclean: clean

clean:
	rm -rf $(NAME)
	make fclean --directory=src/Libft/
	rm -rf capture*.bmp
	rm libmlx.dylib

re: fclean all
