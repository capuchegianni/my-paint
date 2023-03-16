##
## EPITECH PROJECT, 2022
## PROJECT
## File description:
## Makefile to compile the project
##

NAME = my_paint

SRC := 	./src/main.c								\
		./src/menu/menu.c							\
		./src/menu/edition/editionmenu.c			\
		./src/menu/edition/eraser.c					\
		./src/menu/edition/pencil.c					\
		./src/menu/file/filemenu.c					\
		./src/menu/file/newfile.c					\
		./src/menu/file/openfile.c					\
		./src/menu/file/savefile.c					\
		./src/menu/help/helpmenu.c					\
		./src/menu/help/about.c						\
		./src/menu/help/help.c						\
		./src/menu/help/help_text.c 				\
		./src/menu/help/back_button.c				\
		./src/workspace/area.c						\
		./src/workspace/draw.c						\
		./src/menu/help/display_about.c 			\
		./src/tool_bar/bar.c						\
		./src/tool_bar/display_submenu.c			\
		./src/tool_bar/eraser_size/eraser_less.c	\
		./src/tool_bar/eraser_size/eraser_more.c	\
		./src/tool_bar/eraser_size/eraser_size.c	\
		./src/tool_bar/pencil_size/pencil_less.c	\
		./src/tool_bar/pencil_size/pencil_more.c	\
		./src/tool_bar/pencil_size/pencil_size.c	\
		./src/tool_bar/colors/rectangle_color.c 	\
		./src/tool_bar/pencil_shape/pencil_shape.c	\
		./src/tool_bar/pencil_shape/pencil_square.c	\
		./src/tool_bar/pencil_shape/pencil_circle.c	\
		./src/tool_bar/eraser_shape/eraser_shape.c	\
		./src/tool_bar/eraser_shape/eraser_square.c	\
		./src/tool_bar/eraser_shape/eraser_circle.c	\
		./src/menu/edition/bucket.c					\
		./src/workspace/tools_cursor.c 				\

OBJ := $(SRC:.c=.o)

WARNING_FLAGS := -Wall -Wextra -W -g -g3 -ggdb

CSFML_FLAGS := -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIB_FLAGS := -I include/ -L ./lib -lmy -lcsfml

all: $(NAME)

build_lib:
	make -sC lib/my/
	make -sC lib/my_csfml_lib/

$(NAME): $(OBJ)
	make build_lib
	gcc $(SRC) $(WARNING_FLAGS) -o $(NAME) $(LIB_FLAGS) $(CSFML_FLAGS)
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully compiled all the files\e[0m"

clean:
	make clean -sC lib/my/
	make clean -sC lib/my_csfml_lib/
	rm -f $(OBJ)
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully removed .o & .log files\e[0m"

cstyle:
	make fclean -s
	../coding-style-checker/coding-style.sh . .
	../coding-style-checker/print_infos.sh
	make -s

clean_tests:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully removed .gcda, .gcno & .gcov files\e[0m"

fclean: clean clean_tests
	make fclean -sC lib/my/
	make fclean -sC lib/my_csfml_lib/
	rm -f $(NAME)
	rm -f a.out
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully removed binary files\e[0m"

re: fclean all
	make clean

unit_tests: re
	gcc $(SRC) tests/ -lcriterion --coverage -L. -lmy -lcsfml

tests_run: unit_tests
	./$(NAME)

.PHONY: all build_lib clean cstyle clean_tests fclean re unit_tests tests_run
