NAME = a.out

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./get_next_line

SRCS = ./get_next_line/get_next_line.c \
	   ./main.c \
	   ./get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = ./get_next_line/get_next_line.h

all: $(NAME) clean

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
