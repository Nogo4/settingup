##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for bootstrap my_ls
##

SRC = main.c

OBJ = $(SRC:.c=.o)

NAME = setting_up

CFLAGS += -Ilib/include

LIB =	setting_up_lib/lib_setting_up.a \
		lib/libmy.a \

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib
	make -C setting_up_lib
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C lib
	make clean -C setting_up_lib

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)

lib_clean:
	make clean -C lib
