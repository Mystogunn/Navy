##
## Makefile for Makefile in /home/Mystogun/exopis
##
## Made by Josselin COSMAO
## Login   <Mystogun@epitech.net>
##
## Started on  Sat Oct 15 16:46:52 2016 Josselin COSMAO
## Last update Sat Feb 11 02:08:05 2017 Josselin
##

CC	= gcc

RM	= rm -rf

NAME	= navy

SRCS	= main.c \
	  check_pos.c \
	  my_function.c \
	  my_function2.c \
	  first_player.c \
	  second_player.c \
	  catch_signal.c \
	  algo_player1.c \
	  get_next_line.c \
	  trad.c \
	  crypt.c \
	  convert_pos.c \
	  push_to_map.c \
	  algo_player2.c \
	  convert_nbr.c \
	  check_map.c \
	  end_of_game.c \
	  check_pos2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=  -Wextra -Wall -g3 -Iinclude/

all:	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
