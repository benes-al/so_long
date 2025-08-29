# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME        = so_long

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -Iminilibx -g

# Source folders
SRC_DIR     = src

# Source files
SRC_FILES = \
	$(SRC_DIR)/main.c \

# Object files
OBJ_FILES   = $(SRC_FILES:.c=.o)

# MiniLibX
MLX_DIR     = minilibx
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --log-file=valgrind.log \
	         ./$(NAME) maps/map.ber

.PHONY: all clean fclean re valgrind
