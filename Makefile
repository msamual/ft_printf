NAME = libftprintf.a
LIB_NAME = srcs/libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
SRC = srcs/ft_printf.c srcs/parse.c srcs/execute.c srcs/ft_putstr_width.c \
	  srcs/print_string.c srcs/print_pointer.c srcs/print_percent.c \
	  srcs/print_decimal.c srcs/init.c srcs/print_unsigned.c \
	  srcs/ft_itoa_unsigned.c srcs/print_hexadecimal.c srcs/ft_itoa_hex.c
OBJ = $(SRC:.c=.o)
INCLUDES = includes/
LIB = srcs/libft/

.PHONY: all clean fclean re

all: $(NAME)

$(LIB_NAME):
	make -C $(LIB) bonus

libclean:
	Make -C $(LIB) clean

libfclean:
	make -C $(LIB) fclean

libre:
	make -C $(LIB) re

$(NAME): $(OBJ) $(LIB_NAME)
	cp $(LIB_NAME) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

.c.o:
	$(CC) $(FLAGS) $< -o $@ -I $(LIB) -I $(INCLUDES)

clean: libclean
	rm -f $(OBJ) $(BONUSOBJ)

fclean: libfclean clean
	rm -f $(NAME) $(LIB_NAME)

re: clean fclean all
