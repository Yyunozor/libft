# Variables
NAME = libft.a               # Name of the library to create
CC = gcc                     # Compiler to use
CFLAGS = -Wall -Wextra -Werror # Compiler flags
SRC =	ft_islpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bezero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c

#BONUS_SRC = 

OBJ = $(SRC:.c=.o)           # Object files for mandatory part
BONUS_OBJ = $(BONUS_SRC:.c=.o) # Object files for bonus part

# Rule to compile the mandatory part
all: $(NAME)

# Rule to create the library from object files
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)        # Create static library
	@echo "libft.a has been created."

# Rule to compile .c files into .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  # Compile each .c file to .o file
	@echo "Compiled: $<"

# Clean rule - removes object files
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "Object files removed."

# Full clean rule - removes object files and the library
fclean: clean
	@rm -f $(NAME)
	@echo "Library removed."

# Recompile everything
re: fclean all

# Compile bonus part
bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "Bonus part compiled into libft.a."

# Avoid conflicts with files named clean, fclean, etc.
.PHONY: all clean fclean re bonus
