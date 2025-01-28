NAME = fractol 

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -w
RM = rm -f
IFLAGS = -Iminilibx/minilibx-linux
LFLAGS = -Lminilibx/minilibx-linux
OBJ_DIR = ./obj

COMMOM_SRC = sources/keys.c sources/main.c sources/window.c sources/mandelbrot.c sources/parsing.c \
			 sources/tools.c sources/julia.c sources/error.c sources/ft_split.c sources/atof.c 

SRC = $(COMMOM_SRC)

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
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

