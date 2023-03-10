##
## EPITECH PROJECT, 2022
## csfml-lib-makefile
## File description:
## csfml lib Makefile
##

SRC = 	my_close_window.c 					\
		my_window_is_too_small.c 			\
		my_print_text.c						\
		my_background.c 					\
		my_animated_sprite.c 				\
		my_cursor.c 						\
		my_click_sprite.c 					\

OBJ = $(SRC:.c=.o)

NAME = libcsfml.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) *.o
	cp $(NAME) ../
	cp ../../include/my_csfml.h .
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully compiled libcsfml\e[0m"

clean:
	rm -f $(OBJ)
	rm -f *.a

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
