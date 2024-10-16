# Variables
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_isspace.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c

#BONUS_SRC = 

OBJ = $(SRC:.c=.o)
#BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)        # Create static library
	@echo "libft.a has been created."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  # Compile each .c file to .o file
	@echo "Compiled: $<"

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Library removed."

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "Bonus part compiled into libft.a."

.PHONY: all clean fclean re bonus
