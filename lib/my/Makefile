##
## EPITECH PROJECT, 2022
## lib-epitech
## File description:
## lib Makefile
##

SRC = 	my_casesensitive.c 				\
		my_findprimesup.c 				\
		my_free_wordarray.c 			\
		my_getnbr.c 					\
		my_isneg.c 						\
		my_isnum.c 						\
		my_isprime.c 					\
		my_pow.c 						\
		my_printerr.c 					\
		my_printf.c 					\
		my_putchar.c 					\
		my_putfloat.c 					\
		my_putnbr.c 					\
		my_putstr.c 					\
		my_readfile.c 					\
		my_revstr.c 					\
		my_sortintarray.c 				\
		my_sqrt.c 						\
		my_strcat.c 					\
		my_strcmp.c 					\
		my_strcpy.c 					\
		my_strisalpha.c 				\
		my_strlen.c						\
		my_strncat.c 					\
		my_strncmp.c 					\
		my_strncpy.c 					\
		my_strstr.c 					\
		my_swap.c 						\
		my_tablen.c						\
		my_tostr.c						\
		my_wordarray.c 					\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) *.o
	cp $(NAME) ../
	cp ../../include/my.h .
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully compiled libmy\e[0m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
