NAME = fractol 

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -w 
RM = rm -f
IFLAGS = -Iminilibx/minilibx-linux
LFLAGS = -Lminilibx/minilibx-linux
OBJ_DIR = ./obj

SRC = sources/window/keys.c sources/window/window.c \
	  sources/fractal/mandelbrot.c sources/fractal/julia.c \
	  sources/main/main.c sources/main/parsing.c \
	  sources/utils/tools.c sources/utils/error.c \
	  sources/utils/ft_split.c sources/utils/atof.c 

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -lmlx -lXext -lX11 -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

