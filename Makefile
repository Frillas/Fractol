NAME = fractol 

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
IFLAGS = -Iminilibx
LFLAGS = -Lminilibx
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
	make -C minilibx
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -lmlx -lXext -lX11 -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C minilibx

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

