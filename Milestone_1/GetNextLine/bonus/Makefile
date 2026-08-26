NAME = b.out

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ./get_next_line_bonus.c \
	   ./main_bonus.c \
	   ./get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

HEADER = ./get_next_line_bonus.h

all: $(NAME) clean run

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: $(NAME)
	./$(NAME)

re: fclean all

rec: fclean all clean

.PHONY: all clean fclean re rec
