# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME        = get_next_line.a

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes

# Source folders
SRC_DIR     = src

# Source files
SRC_FILES = \
	$(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/get_next_line_utils.c \

# Object files
OBJ_FILES   = $(SRC_FILES:.c=.o)

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re