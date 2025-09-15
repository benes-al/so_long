# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

# Program name
NAME        = so_long

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -fPIC\
				$(SO_LONG_INC) \
				$(FT_PRINTF_INC) \
				$(GET_NEXT_LINE_INC) \
				$(LIBFT_INC) \
				$(MLX_INC)

# Source and object directories
SRC_DIR     = src
OBJ_DIR     = objects

# External libraries
FT_PRINTF_DIR		= libs/ft_printf
GET_NEXT_LINE_DIR	= libs/get_next_line
LIBFT_DIR			= libs/libft
MLX_DIR				= libs/minilibx

FT_PRINTF_LIB		= $(FT_PRINTF_DIR)/ft_printf.a
GET_NEXT_LINE_LIB	= $(GET_NEXT_LINE_DIR)/get_next_line.a
LIBFT_LIB			= $(LIBFT_DIR)/libft.a
MLX_LIB 			= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Include paths
SO_LONG_INC			= -Iincludes
FT_PRINTF_INC		= -I$(FT_PRINTF_DIR)/includes
GET_NEXT_LINE_INC 	= -I$(GET_NEXT_LINE_DIR)/includes
LIBFT_INC			= -I$(LIBFT_DIR)/includes
MLX_INC				= -I$(MLX_DIR)

# Source files (paths relative to SRC_DIR or full path)
SRC_FILES = \
	init_game.c \
	render_move.c \
	run_game.c \
	are_valid_characters.c \
	check_args.c \
	create_map.c \
	is_map_enclosed_by_walls.c \
	is_valid_file_name.c \
	is_valid_grid_size.c \
	is_valid_map.c \
	is_valid_path.c \
	parse_map.c \
	file_in_one_line.c \
	ft_exit_error.c \
	ft_exit_esc.c \
	ft_exit_game.c \
	ft_free_array.c  \
	ft_free_game.c \
	ft_strclen.c \
	main.c

# Convert source files to object files with prefix
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Tell make where to find source files
VPATH = src src/parser src/utils src/game

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) \
		$(FT_PRINTF_LIB) \
		$(GET_NEXT_LINE_LIB) \
		$(LIBFT_LIB) \
		$(MLX_LIB) \
		-o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE_LIB):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR) -f Makefile.mk

valgrind: $(NAME)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --log-file=valgrind.log \
	         ./$(NAME) maps/map.ber

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	rm -f $(MLX_DIR)/*.o $(MLX_DIR)/*.a

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	rm -f $(MLX_DIR)/*.o $(MLX_DIR)/*.a

re: fclean all

.PHONY: all clean fclean re valgrind
