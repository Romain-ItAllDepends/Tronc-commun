NAME=libftprintf.a

MY_SOURCES=	ft_printf.c \
		LIBFT/ft_strlen.c \
		LIBFT/ft_putstr_fd.c \
		LIBFT/ft_putnbr_fd.c \
		LIBFT/ft_putchar_fd.c \
		LIBFT/ft_puthex_fd.c \
		LIBFT/ft_putnbru_fd.c \
		LIBFT/ft_putptr_fd.c
		

MY_OBJECTS=$(MY_SOURCES:.c=.o)

RM=rm -f

CC=cc
ARRC=ar -rcs
FLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	$(ARRC) $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
