CC=cc
CFLAGS=-Wall -Wextra -Werror -g

NAME=so_long

SRC= srcs/main.c srcs/img.c srcs/map.c srcs/game.c srcs/movement.c srcs/collectables.c srcs/map_check.c srcs/close.c
OBJ=$(SRC:.c=.o)

MLX_DIR=mlx_linux
MLX_LIB=$(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR=libft
LIBFT_A=$(LIBFT_DIR)/libft.a

INCLUDES=-I$(MLX_DIR) -I/usr/include -I$(LIBFT_DIR)

MLX_LINK=-L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(MLX_LIB) $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LINK) $(LIBFT_A) -o $(NAME)

$(MLX_LIB):
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)

re: fclean all
