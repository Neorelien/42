# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 12:36:37 by awery             #+#    #+#              #
#    Updated: 2020/11/21 00:02:38 by awery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isprint.c ft_memset.c ft_strdup.c ft_strnstr.c ft_bzero.c ft_itoa.c \
	ft_putchar_fd.c ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memccpy.c \
	ft_putendl_fd.c ft_strlcat.c ft_strtrim.c ft_isalnum.c ft_memchr.c \
	ft_putnbr_fd.c ft_strlcpy.c ft_substr.c ft_isalpha.c ft_memcmp.c ft_putstr_fd.c \
	ft_strlen.c ft_tolower.c ft_isascii.c ft_memcpy.c ft_split.c ft_strmapi.c \
	ft_toupper.c ft_isdigit.c ft_memmove.c ft_strchr.c ft_strncmp.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -c $(SRC) ; ar rc $(NAME) *.o

bonus:
	clang -Wall -Wextra -Werror -c $(SRC) $(BONUS); ar rc $(NAME) *.o 
	
clean:
	rm -f *.o *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
