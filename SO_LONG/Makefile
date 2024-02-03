NAME = so_long

MY_SOURCES=	so_long.c \
		ft_split.c \
		calloc_free.c \
		init_map_functions.c \
		little_functions.c \
		map_finishable.c \
		parse_map.c \
		move.c \
		FT_PRINTF/ft_printf.c \
		FT_PRINTF/LIBFT/ft_strlen.c \
		FT_PRINTF/LIBFT/ft_putstr_fd.c \
		FT_PRINTF/LIBFT/ft_putnbr_fd.c \
		FT_PRINTF/LIBFT/ft_putchar_fd.c \
		FT_PRINTF/LIBFT/ft_puthex_fd.c \
		FT_PRINTF/LIBFT/ft_putnbru_fd.c \
		FT_PRINTF/LIBFT/ft_putptr_fd.c

red='\033[0;31m'
green='\033[0;32m'
orange='\033[0;33m'
blue='\033[0;34m'
purple='\033[0;35m'
cyan='\033[0;36m'
light_grey='\033[0;37m'
light_red='\033[1;31m'
light_green='\033[1;32m'
light_orange='\033[1;33m'
light_blue='\033[1;34m'
light_purple='\033[1;35m'
light_cyan='\033[1;36m'
white='\033[1;37m'
green_c='\033[6;32m'

MY_OBJECTS=$(MY_SOURCES:.c=.o)

RM=rm -f

CC=clang
FLAGS=-Wall -Wextra -Werror -I./MLX42/include -g
MLXFLAGS= -ldl -lX11 -lglfw -lm -lz -lbsd -lXext 

all: $(NAME)


$(NAME) : $(MY_OBJECTS)
	make --directory ./MLX42/build
	$(CC) $(FLAGS) $(MY_OBJECTS) $(MLXFLAGS) ./MLX42/build/libmlx42.a -o $@
	@clear
	@if [ $$? -eq 0 ]; then \
		echo $(light_cyan)"\t   »»-————　Make　————-««\n"; \
	fi

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
clean: 
	@$(RM) $(MY_OBJECTS)
	@echo $(light_green)"\t  »»-————　Clean　————-««\n"

fclean: clean
	@$(RM) $(NAME)
	@echo $(white)"\t»»-————　Full clean　————-««\n"

re: fclean all
	@echo $(green_c)"\t   »»-————　Done　————-««"

.PHONY: all clean fclean re
