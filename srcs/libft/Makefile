NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_calloc.c ft_strlcpy.c \
ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_tolower.c ft_toupper.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_putnbr_base.c \
ft_putchar.c ft_putnbr.c ft_putstr.c
OBJ = $(SRC:.c=.o)
BONUSOBJ = $(SRCBONUS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: libftbonus

libftbonus: $(OBJ) $(BONUSOBJ)
	ar rc $(NAME) $(OBJ) $(BONUSOBJ)
	ranlib $(NAME)

.c.o: libftbonus $(OBJ) $(BONUSOBJ)
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all
