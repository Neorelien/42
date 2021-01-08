# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 12:00:36 by awery             #+#    #+#              #
#    Updated: 2020/12/22 18:24:51 by Aurelien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printf.c is_d.c is_c.c error_tools.c str_browse.c is_p.c is_u.c is_x.c is_s.c is_pourcent.c


all: $(NAME)

$(NAME):
	make -C libft/ ; cp libft/libft.a libftprintf.a ; cd printfsrc ; clang  -Wall -Wextra -Werror -c $(SRC) ; cd ../ ; ar rc $(NAME) printfsrc/*.o

clean:
	make fclean -C libft/ ; rm -rf printfsrc/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
