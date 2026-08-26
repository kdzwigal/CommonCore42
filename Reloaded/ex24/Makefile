# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS = ./srcs/ft_putchar.c \
	./srcs/ft_putstr.c \
	./srcs/ft_strcmp.c \
	./srcs/ft_strlen.c \
	./srcs/ft_swap.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I/includes

#main rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#pattern rule
%.o : %.c
	$(CC) $(CFALGS) -c $< -o $@

#clean rule
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
