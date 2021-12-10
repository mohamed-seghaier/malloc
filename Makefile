##
## EPITECH PROJECT, 2019
## PSU_2018_malloc
## File description:
## Makefile
##

NAME	= libmy_malloc.so

CC	= gcc

RM	= rm -f

SRCS	= my_malloc.c \
	  node.c

CFLAGS = -I 
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	 $(CC) -shared -fPIC $(SRCS) -o $(NAME) $(LDFLAGS)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
