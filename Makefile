# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

# Program name
NAME        = so_long

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g \
				$(SO_LONG_INC) \
				$(FT_PRINTF_INC) \
				$(GET_NEXT_LINE_INC) \
				$(LIBFT_INC) 

# Source and object directories
SRC_DIR     = src
PAR_DIR		= src/parser 
UTI_DIR		= src/utils
OBJ_DIR     = objects

# External libraries
FT_PRINTF_DIR		= libs/ft_printf
GET_NEXT_LINE_DIR	= libs/get_next_line
LIBFT_DIR			= libs/libft

FT_PRINTF_LIB		= $(FT_PRINTF_DIR)/ft_printf.a
GET_NEXT_LINE_LIB	= $(GET_NEXT_LINE_DIR)/get_next_line.a
LIBFT_LIB			= $(LIBFT_DIR)/libft.a

# Include paths
SO_LONG_INC			= -Iincludes
FT_PRINTF_INC		= -I$(FT_PRINTF_DIR)/includes
GET_NEXT_LINE_INC 	= -I$(GET_NEXT_LINE_DIR)/includes
LIBFT_INC			= -I$(LIBFT_DIR)/includes

# Source files
SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/is_valid_filename.c \
	$(PAR_DIR)/is_valid_grid_size.c  \
	$(PAR_DIR)/is_valid_map.c  \
	$(UTI_DIR)/map_in_one_line.c  \
	$(UTI_DIR)/ft_strclen.c \
	$(UTI_DIR)/ft_exit_error.c

# Convert src/file.c → objects/src/file.o
OBJ_FILES   = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

# Default target
all: $(NAME)

# Linking the final executable
$(NAME): $(OBJ_FILES) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) \
		$(FT_PRINTF_LIB) \
		$(GET_NEXT_LINE_LIB) \
		$(LIBFT_LIB) \
		-o $(NAME)

# Rule to compile each .c file into a corresponding .o file in the objects/ dir
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build the external libraries
$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)
$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)
$(GET_NEXT_LINE_LIB):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

# Run valgrind test
valgrind: $(NAME)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --log-file=valgrind.log \
	         ./$(NAME) maps/map.ber

# clean: Clean object files only
# fclean: Clean all (objects + binaries + libs)
# re: Full rebuild
# PHONY: Declare phony targets to avoid conflicts with files named like these
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all clean fclean re valgrind