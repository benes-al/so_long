# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME        = so_long

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -g

# Source folders
SRC_DIR     = src
HELPE_DIR	= $(SRC_DIR)/helpers
PROGR_DIR   = $(SRC_DIR)/program
PIPE__DIR	= $(SRC_DIR)/pipe
UTILS_DIR   = $(SRC_DIR)/utils
MAIN__DIR	= $(SRC_DIR)

# Source files
SRC_FILES = \
	$(HELPE_DIR)/ft_bzero.c \
	$(HELPE_DIR)/ft_strncmp.c \
	$(PROGR_DIR)/child1_process.c \
	$(UTILS_DIR)/ft_error.c \
	$(MAIN__DIR)/main.c \

# Object files
OBJ_FILES   = $(SRC_FILES:.c=.o)

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	@echo "$(YELLOW)Valgrind Report$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
	--track-origins=yes --trace-children=yes \
	./$(NAME) infile wc "cat -e" outfile

.PHONY: all clean fclean re