# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 12:00:36 by awery             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/03/03 19:32:05 by aurelien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
=======
#    Updated: 2021/03/03 09:44:36 by awery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
>>>>>>> 07066133819c9328089f4baf718b6d65ff143529

all: linux

linux:
	make -C minilibx ; cd src/Libft ; make ; cd ../../ ; clang -Wall -Werror -Wextra -Ofast -D BUFFER_SIZE=20 exit.c to_bmp_2.c texture_init.c texture_2.c td_2.c sprite_2.c player_move_2.c map_checker_2.c element_3.c element_2.c display_2.c direction_support.c direction_2.c raycasting_2.c raycasting_1.c pos.c arg_checker.c closing.c sprite.c to_bmp.c td.c cubetd.c texture.c direction.c map_checker.c display.c elements.c player_move.c  src/get_next_line.c src/get_next_line_utils.c src/Libft/libft.a minilibx/libmlx_Linux.a -lm -lbsd -lX11 -lXext -o $(NAME)

fclean: clean

clean:
	make clean -C minilibx
	rm -rf $(NAME)
	make fclean --directory=src/Libft/
	rm -rf capture*.bmp

re: fclean linux
