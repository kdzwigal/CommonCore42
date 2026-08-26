NAME = push_swap
BONAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -I./bonus

BONSRCS = ./bonus/main.c \
	./bonus/parser.c \
	./bonus/checker_utils.c \
	./bonus/ft_split.c \
	./bonus/handle_error.c \
	./bonus/operations/ps_push.c \
	./bonus/operations/ps_swap.c \
	./bonus/operations/ps_rotate.c \
	./bonus/operations/ps_rev_rotate.c

SRCS = ./main.c \
	./parser.c \
	./parser_utils.c \
	./push_swap_utils.c \
	./ft_split.c \
	./ft_printf.c \
	./ft_printf_put.c \
	./handle_error.c \
	./sort_simple.c \
	./sort_medium.c \
	./sort_medium_utils.c \
	./sort_complex.c \
	./sort_complex_utils.c \
	./init_and_start.c \
	./operations/ps_push.c \
	./operations/ps_swap.c \
	./operations/ps_rotate.c \
	./operations/ps_rev_rotate.c

OBJS = $(SRCS:.c=.o)

BONOBJS = $(BONSRCS:.c=.o)

HEADER = ./push_swap.h

BONHEADER = ./bonus/checker.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(HEADER)
$(BONOBJS): $(BONHEADER)

bonus: $(BONAME)

$(BONAME): $(BONOBJS)
	$(CC) $(CFLAGS) $(BONOBJS) -o $(BONAME)

clean:
	rm -f $(OBJS) $(BONOBJS)

fclean: clean
	rm -f $(NAME) $(BONAME)

run: $(NAME)
	./$(NAME)

re: fclean all

rec: fclean all clean

.PHONY: all clean fclean re rec bonus
