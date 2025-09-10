# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME        = ft_printf.a

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes

# Source folders
SRC_DIR     = src

# Source files
SRC_FILES = \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/helper_ft_print_args.c \
	$(SRC_DIR)/helper_ft_putchar.c \
	$(SRC_DIR)/helper_ft_puthex.c \
	$(SRC_DIR)/helper_ft_putnbr.c \
	$(SRC_DIR)/helper_ft_putptr.c \
	$(SRC_DIR)/helper_ft_putstr.c \
	$(SRC_DIR)/helper_ft_putuint.c

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