##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

CC = gcc

SRC =	src/my_builtins.c		\
		src/execution.c			\
		src/manage_cd.c 		\
		src/priorities.c 		\
		src/setenv.c 			\
		src/unsetenv.c 			\
		src/cp_env.c 			\
		src/cd_cmd.c 			\
		lib/my_strncmp.c 		\
		lib/clear_str.c 		\
		lib/my_str_to_word_array.c		\
		lib/my_putstr.c		\
		lib/my_strcpy.c		\
		lib/my_strlen.c		\
		lib/my_putchar.c		\
		lib/my_strcat.c	\
		lib/my_strcmp.c	\
		lib/my_strdup.c	\


SRC_MAIN = src/main.c

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

CFLAGS = -Wall -Wextra -pedantic

CPPFLAGS = -I./include

NAME = mysh

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN)
	@       tput setaf 1; cat include/art; tput sgr0

debug: CFLAGS += -g3
debug: re

clean:
	rm -f $(OBJ) $(OBJ_MAIN)

fclean:	clean
	rm -f *gmon*
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f src/*~
	rm -f src/\*#
	rm -f include/*~
	rm -f include/*#

re: fclean all

.PHONY: all clean fclean re
