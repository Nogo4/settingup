##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for seeting up project
##

SRC =  lib/src/count_x.c \
	   lib/src/skip_height.c \
	   lib/src/count_y.c \
	   lib/src/is_a_good_file_and_map.c \

OBJ = $(SRC:.c=.o)

NAME = lib_setting_up.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc lib_setting_up.a $(OBJ)

clean:
	rm -f lib/*.o
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)
