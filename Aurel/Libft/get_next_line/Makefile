NAME = libft.a

SRC = get_next_line.c get_next_line_utils.c 

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -D BUFFER_SIZE=200 -c $(SRC) 
clean:
	rm -f *.o *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
