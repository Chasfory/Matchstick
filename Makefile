##
## EPITECH PROJECT, 2021
##
## File description:
##

SRC			=	src/main.c\
				src/check_error.c\
				src/error_handling.c\
				src/game_players.c\
				src/gameplay.c\
				src/outils.c\
				src/play_game.c\
				src/remote_stick.c\
				src/win_lose.c\

OBJ			=	$(SRC:.c=.o)

NAME		=	matchstick

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include

LDFLAGS		=	-L ./lib -lmy

CC			=	gcc

all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all

./PHONY: all clean fclean