# Nazwa pliku wynikowego
NAME = tests_libft.out

NAME2 = test_son_lst.out

NAME1 = test_son.out

# Kompilator
CC = cc

# Flagi kompilacji (-I./libft pozwala na dodawanie nagłówka przez #include "libft.h" zamiast pełnej ścieżki)
CFLAGS = -Wall -Wextra -Werror -I./libft

# Pliki źródłowe i odpowiadające im pliki obiektowe
SRCS = main.c

SRCS1 = test_sonia_libft.c

SRCS2 = test_sonia_lst.c

OBJS = $(SRCS:.c=.o)

OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

# Ścieżka do biblioteki statycznej i nagłówka
LIBFT = ./libft/libft.a
HEADER = ./libft/libft.h

# Reguła domyślna
all: $(NAME)

son: $(NAME1)

sonlst: $(NAME2)

# Linkowanie programu końcowego
# Reguła zależy od plików obiektowych oraz od samej biblioteki .a
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME1): $(OBJS1) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS1) $(LIBFT) -lbsd -o $(NAME1)
	
$(NAME2): $(OBJS2) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS2) $(LIBFT) -lbsd -o $(NAME2)

# Kompilacja plików źródłowych do obiektowych
# Dodanie $(HEADER) jako zależności sprawi, że zmiana w libft.h wymusi rekompilację main.c
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików obiektowych
clean:
	rm -f $(OBJS)

# Pełne czyszczenie (pliki obiektowe + plik wykonywalny)
fclean: clean
	rm -f $(NAME)

# Wymuszenie rekompilacji od zera
re: fclean all

# Deklaracja celów, które nie są fizycznymi plikami
.PHONY: all clean fclean re
