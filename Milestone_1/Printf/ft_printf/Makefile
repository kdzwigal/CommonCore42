# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ./ft_printf.c \
	./print_hex.c \
	./print_scn.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I.

#main rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#pattern rule
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean rule
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
