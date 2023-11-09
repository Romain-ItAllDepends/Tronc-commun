NAME=libft.a

MY_SOURCES=ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c \
			ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c \
			ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
			ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c ft_memchr.c \
			ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
			ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
			ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c

MY_OBJECTS=$(MY_SOURCES:.c=.o)

RM=rm -f

CC=cc
ARRC=ar -rc
FLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	$(ARRC) $(NAME) $(MY_OBJECTS)
	
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

my_rule: $(shell pwd)

clean: 
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
