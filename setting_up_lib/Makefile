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
	   lib/src/my_argc.c \
	   lib/src/my_str_to_word_array.c \
	   lib/setting_up_basic.c \
	   lib/src/special_case.c \
	   lib/src/check_error_generate.c \

OBJ = $(SRC:.c=.o)

NAME = lib_setting_up.a

CFLAGS += -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc lib_setting_up.a $(OBJ)

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)
